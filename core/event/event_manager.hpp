#ifndef __EVENT_MANAGER_HPP__
#define __EVENT_MANAGER_HPP__

#include "event.hpp"
#include "game_objects/game_object.hpp"

#include <cstdint>
#include <map>
#include <memory>
#include <queue>
#include <vector>

using SubscriptionEventType = std::pair<EventType, std::uint32_t>;

class EventManager {
public:
    static void pushEvent(std::unique_ptr<Event>);
    std::unique_ptr<Event> popEvent();

    void run();
    void stop();

    bool isRunning() { return m_isRunning; }

    bool subscribeOnEvent(SubscriptionEventType type, std::shared_ptr<GameObject> object);

    static EventManager* getManager();

protected:
    EventManager();
    ~EventManager();

    static void handleEvents();

private:
    static EventManager* m_manager;
    std::queue<std::unique_ptr<Event>> m_eventsQueue;
    std::map<SubscriptionEventType, std::vector<std::shared_ptr<GameObject>>> m_subscriptions;
    bool m_isRunning;
};

#endif /* __EVENT_MANAGER_HPP__ */
