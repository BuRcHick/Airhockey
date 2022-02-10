#include "event_manager.hpp"
#include "logger/logger.hpp"

#include <thread>
#include <chrono>

std::chrono::milliseconds interval(100);

EventManager* EventManager::m_manager = nullptr;

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

void EventManager::pushEvent(std::shared_ptr<Event> event)
{
    EventManager* manager = getManager();

    std::lock_guard<std::mutex> lk(manager->m_mutex);
    manager->m_eventsQueue.push(event);
    manager->m_condVariable.notify_one();
}

std::shared_ptr<Event> EventManager::popEvent()
{
    std::shared_ptr<Event> event = nullptr;

    std::unique_lock<std::mutex> lk(m_mutex);
    m_condVariable.wait(lk, [this]{ return !m_eventsQueue.empty(); });
    event = m_eventsQueue.front();
    m_eventsQueue.pop();

    return event;
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

void processSubscriptions(SubscriptionMap const& map, std::shared_ptr<Event> event)
{
    for (auto subscrbsion : map) {
        if (isSubscribed(event.get(), subscrbsion.first)) {
            for (auto subscriber : subscrbsion.second) {
                subscriber->handleEvent(event.get());
            }
        }
    }

}

void EventManager::handleEvents()
{
    EventManager* manager = getManager();
    std::shared_ptr<Event> event = nullptr;

    event = manager->popEvent();

    switch (event->type) {
        case EventType::SDL_Event: {
            SDL_Event* sdl_event = &event->data.sdl_event;

            if (SDL_QUIT == sdl_event->type) {
                manager->m_isRunning = false;
            }

            processSubscriptions(manager->m_subscriptions, event);

            break;
        }
        case EventType::GameEvent:
            processSubscriptions(manager->m_subscriptions, event);

            break;
        default:
            break;
    }
}

void EventManager::task()
{
    EventManager* manager = getManager();
    std::this_thread::sleep_for(interval);

    while (manager->isRunning()) {
        handleEvents();
    }
}

void EventManager::stop()
{
    SDL_Event sdl_event = {
        .type = SDL_QUIT
    };
    std::shared_ptr<Event> event = std::make_shared<Event>();

    event->type = EventType::SDL_Event;
    event->data.sdl_event = sdl_event;

    pushEvent(event);
}

void EventManager::run()
{
    if (false == m_isRunning) {
        m_isRunning = true;
        std::thread thread(EventManager::task);
        thread.detach();
    }
}
