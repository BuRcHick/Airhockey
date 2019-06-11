#ifndef CGAME
#define CGAME
#include "cgameobj.hpp"
#include "cwindow.hpp"
#include <memory>
#include <unordered_map>

class CGame
{
private:
	bool running;
	CWindow* mainWnd;
	std::unordered_map<std::string, std::unique_ptr<CGameObj> > objects;
	CGame();
	~CGame();
	static CGame* gameInst;
public:
	CGame(const CGame&) = delete;
	CGame& operator = (const CGame&) = delete;
	CGame(CGame&&) = delete;
	static CGame* getGameInst();
	bool initMainWindow(u_int32_t initF, const std::string& title, int x, int y, int w, int h, u_int32_t wndFlags);
	bool addObject(const std::string&, std::unique_ptr<CGameObj>);
	void removeObject(const std::string&);
	//std::unique_ptr<CGameObj> getGameObj(const std::string&);
	void gameProcces();
	void draw();
	CWindow* getGame()const{return mainWnd;};
};

#endif //CGAME