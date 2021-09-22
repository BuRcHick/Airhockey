#ifndef CPRESET
#define CPRESET
#include <functional>
#include <string>

enum class PresetStates{
    atctive,
    inactive
};


class CPreset
{
private:
    std::function<void()> preset;
    PresetStates state;
public:
    CPreset(/* args */);
    ~CPreset();
    CPreset(const CPreset&) = delete;
    CPreset& operator = (const CPreset&) = delete;
    void createPreset(const std::function<void()>& _preset){preset = _preset;};
    void runPreset()const{ if(state == PresetStates::atctive) preset(); };
    void setState(PresetStates _state){state =_state;};
    const PresetStates getState() const {return state;};
};

#endif //CPRESET
