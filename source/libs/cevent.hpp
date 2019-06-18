#ifndef CEVENT
#define CEVENT
#include <stdio.h>
#include <functional>
#include <algorithm>
#include <initializer_list>

enum class UserEvents{
	GameOver,
	GamePause,
	CounterUpdate,
	CounterReset,
	ObjectShow,
	ObjectRemove,
	ObjectUpdate,
	ObjectCreate,
	ObjectMove,
	ObjectMoveLeft,
	ObjectMoveRight,
	ObjectMoveUp,
	ObjectMoveDown,
	PressEnter,
	SwitchToAnotherPresset
};

class CEvent
{
private:
	std::function<void()> func;
public:
	CEvent();
	CEvent(const std::function<void()>& _func)
		:func(_func)
	{};
	~CEvent();
	void setFunc(const std::function<void()>&);
	void execFunc();
};


#endif //CEVENT