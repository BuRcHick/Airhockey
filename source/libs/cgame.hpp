#ifndef CGAME
#define CGAME
#include "cgameobj.hpp"
#include "window/window.hpp"
#include "сeventmanager.hpp"
#include <memory>
#include <unordered_map>
#include <functional>
#include "cpreset.hpp"
#include "ctext.hpp"
class CGame
{
public:
    CGame(const CGame&) = delete;
    CGame& operator = (const CGame&) = delete;
    CGame(CGame&&) = delete;

    static CGame* getGameInst();
    void init(int initF);
    bool addObject(const std::string&, std::shared_ptr<CGameObj>);
    void removeObject(const std::string&);
    void gameProcess();
    void draw();
    Window* getGameWindow()const{return mainWnd;};
    void moveObject(const std::string&, int, int);
    void moveObjectTo(const std::string&, int, int);
    void setGameEventsHendlers(const std::function<void()>&);
    const std::shared_ptr<CGameObj> getObj(const std::string& key) const {return objects.find(key)->second; };
    void changeGameProcess(bool run){running = run;};
    void ereseGameObjects(){objects.clear();};
    bool ifRunning()const {return running;};
    bool ifObjectsEmpty()const {return objects.empty();};

private:
    bool running;
    Window* mainWnd;
    std::unordered_map<std::string, std::shared_ptr<CGameObj> > objects;
    std::function<void()> handleGameEvents;
    CGame();
    ~CGame();
    static CGame* gameInst;
};

#endif //CGAME
