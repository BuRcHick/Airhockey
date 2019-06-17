#ifndef CGAME
#define CGAME
#include "cgameobj.hpp"
#include "cwindow.hpp"
#include "сeventmanager.hpp"
#include <memory>
#include <unordered_map>
#include <functional>
#include "cpreset.hpp"
class CGame
{
private:
	bool running;
	CWindow* mainWnd;
	std::unordered_map<std::string, std::shared_ptr<CGameObj> > objects;
	std::unordered_map<std::string, std::unique_ptr<CPreset> > presets;
	CGame();
	~CGame();
	static CGame* gameInst;
public:
	CGame(const CGame&) = delete;
	CGame& operator = (const CGame&) = delete;
	CGame(CGame&&) = delete;
	static CGame* getGameInst();
	void initMainWindow(u_int32_t initF, const std::string& title, int x, int y, int w, int h, u_int32_t wndFlags);
	bool addObject(const std::string&, std::shared_ptr<CGameObj>);
	void removeObject(const std::string&);
	void gameProcess();
	void draw();
	CWindow* getGameWindow()const{return mainWnd;};
	void moveObject(const std::string&, int, int);
	void moveObjectTo(const std::string&, int, int);
	void handleGameEvents();
	const std::shared_ptr<CGameObj> getObj(const std::string& key) const {return objects.find(key)->second; };
	bool ifPresetExcist(const std::string& descr)const{return presets.find(descr) != presets.end();};
	bool addPreset(const std::string&,std::unique_ptr<CPreset>);
	bool removePreset(const std::string&);
	bool updatePreset(const std::string&,std::function<void()>);
	bool runPreset(const std::string&);
};

#endif //CGAME