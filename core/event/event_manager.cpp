#include "event_manager.hpp"

#include <thread>

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

void EventManager::pushEvent(std::unique_ptr<Event> event)
{
    EventManager* manager = getManager();

    manager->m_eventsQueue.push(std::move(event));

}

std::unique_ptr<Event> EventManager::popEvent()
{
    return std::move(m_eventsQueue.back());
}

bool EventManager::subscribeOnEvent(SubscriptionEventType type, std::shared_ptr<GameObject> object)
{
    if (m_subscriptions.find(type) != m_subscriptions.end()) {
        return false;
    }

    m_subscriptions[type] = object;

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
        event_ptr = event.get();

        switch (event.get()->type) {
            case EventType::SDL_Event: {
                SDL_Event* sdl_event = &event_ptr->data.sdl_event;

                if (SDL_QUIT == sdl_event->type) {
                    manager->m_isRunning = false;
                }

                for (auto subscrbsion : manager->m_subscriptions) {
                    if (isSubscribed(event_ptr, subscrbsion.first)) {
                        subscrbsion.second.get()->handleEvent(event.get());
                    }
                }

                break;
            }
            case EventType::GameEvent:
                for (auto subscrbsion : manager->m_subscriptions) {
                    if (isSubscribed(event_ptr, subscrbsion.first)) {
                        subscrbsion.second.get()->handleEvent(event.get());
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
    EventManager* manager = getManager();
    SDL_Event sdl_event = {
        .type = SDL_QUIT
    };
    std::unique_ptr<Event> event;

    event = std::make_unique<Event>();

    event->type = EventType::SDL_Event;
    event->data.sdl_event = sdl_event;

    manager->pushEvent(std::move(event));
}

void EventManager::run()
{
    if (false == EventManager::getManager()->isRunning()) {
        std::thread thread(EventManager::handleEvents);
        thread.detach();
        EventManager::getManager()->m_isRunning = true;
    }

}
