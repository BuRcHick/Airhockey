#include "event_manager.hpp"
#include "logger/logger.hpp"

#include <thread>
#include <mutex>

EventManager* EventManager::m_manager = nullptr;
std::mutex g_mutex;

EventManager::EventManager()
{
    m_isRunning = false;
}

EventManager::~EventManager()
{
    m_subscriptions.clear();
}


EventManager* EventManager::getManager()
{
    if (nullptr == m_manager) {
        m_manager = new EventManager();
    }

    return m_manager;
}

void EventManager::pushEvent(std::unique_ptr<Event> event)
{
    EventManager* manager = getManager();

    g_mutex.lock();
    manager->m_eventsQueue.push(std::move(event));
    g_mutex.unlock();

}

std::unique_ptr<Event> EventManager::popEvent()
{
    std::unique_ptr<Event> event;

    if (m_eventsQueue.empty()) {
        return nullptr;
    }

    g_mutex.lock();
    event = std::move(m_eventsQueue.back());
    g_mutex.unlock();

    return std::move(event);
}

bool EventManager::subscribeOnEvent(SubscriptionEventType type, std::shared_ptr<GameObject> object)
{
    if (m_subscriptions.find(type) != m_subscriptions.end()) {
        LOG_WARNING("Cannot find: type = {%d, %d}\n", type.first, type.second);

        return false;
    }

    for (auto subscriber : m_subscriptions[type]) {
        if (object == subscriber) {
            LOG_WARNING("Object already subpscribed\n");

            return false;
        }
    }

    m_subscriptions[type].push_back(object);

    return true;
}

bool isSubscribed(Event const* event, const SubscriptionEventType& type)
{
    switch (type.first) {
        case EventType::SDL_Event:
            if (EventType::SDL_Event == event->type
                && type.second == event->data.sdl_event.type) {
                return true;
            }

            break;
        case EventType::GameEvent:
            if (EventType::GameEvent == event->type
                && type.second == event->data.game_event.type) {
                return true;
            }

            break;
        default:
            return false;
    }

    return false;
}

void EventManager::handleEvents()
{
    EventManager* manager = getManager();
    std::unique_ptr<Event> event;
    Event* event_ptr = nullptr;

    while (manager->isRunning()) {
        event = manager->popEvent();
        if (!event) {
            continue;
        }

        event_ptr = event.get();

        switch (event.get()->type) {
            case EventType::SDL_Event: {
                SDL_Event* sdl_event = &event_ptr->data.sdl_event;

                if (SDL_QUIT == sdl_event->type) {
                    manager->m_isRunning = false;
                }

                for (auto subscrbsion : manager->m_subscriptions) {
                    if (isSubscribed(event_ptr, subscrbsion.first)) {
                        for (auto subscriber : subscrbsion.second) {
                            subscriber->handleEvent(event.get());
                        }
                    }
                }

                break;
            }
            case EventType::GameEvent:
                for (auto subscrbsion : manager->m_subscriptions) {
                    if (isSubscribed(event_ptr, subscrbsion.first)) {
                        for (auto subscriber : subscrbsion.second) {
                            subscriber->handleEvent(event.get());
                        }
                    }
                }

                break;
            default:
                break;
        }
    }
}

void EventManager::stop()
{
    SDL_Event sdl_event = {
        .type = SDL_QUIT
    };
    std::unique_ptr<Event> event;

    event = std::make_unique<Event>();

    event->type = EventType::SDL_Event;
    event->data.sdl_event = sdl_event;

    pushEvent(std::move(event));
}

void EventManager::run()
{
    if (false == m_isRunning) {
        m_isRunning = true;

        std::thread thread(EventManager::handleEvents);
        thread.detach();
    }

}
