#include "cevent.hpp"
CEvent::CEvent(/* args */)
{
}

CEvent::~CEvent()
{
}

void CEvent::setFunc(const std::function<void()>& _func){
    func = _func;
}

void CEvent::execFunc(){
    func();
}
