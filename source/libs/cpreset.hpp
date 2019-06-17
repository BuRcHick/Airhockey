#ifndef CPRESET
#define CPRESET
#include <functional>
#include <string>

class CPreset
{
private:
	std::function<void()> preset;
public:
	CPreset(/* args */);
	~CPreset();
	CPreset(const CPreset&) = delete;
	CPreset& operator = (const CPreset&) = delete;
	void createPreset(const std::function<void()>& _preset){preset = _preset;};
	void runPreset()const{ preset(); };
};

#endif //CPRESET