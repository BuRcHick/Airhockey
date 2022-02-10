#ifndef __EVENT_MANAGER_HPP__
#define __EVENT_MANAGER_HPP__

#include "event.hpp"
#include "game_objects/game_object.hpp"

#include <cstdint>
#include <map>
#include <memory>
#include <queue>
#include <vector>
#include <mutex>
#include <condition_variable>

using SubscriptionEventType = std::pair<EventType, std::uint32_t>;
using SubscriptionMap = std::map<SubscriptionEventType, std::vector<std::shared_ptr<GameObject>>>;

class EventManager {
public:
    static void pushEvent(std::shared_ptr<Event> event);
    std::shared_ptr<Event> popEvent();

    void run();
    void stop();

    bool isRunning() { return m_isRunning; }

    bool subscribeOnEvent(SubscriptionEventType type, std::shared_ptr<GameObject> object);

    static EventManager* getManager();
    static void handleEvents();

protected:
    EventManager();
    ~EventManager();

    static void task();

private:
    static EventManager* m_manager;
    std::queue<std::shared_ptr<Event>> m_eventsQueue;
    SubscriptionMap m_subscriptions;
    bool m_isRunning;
    std::mutex m_mutex;
    std::condition_variable m_condVariable;
};

#endif /* __EVENT_MANAGER_HPP__ */
