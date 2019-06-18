#ifndef CPRESETMANAGER
#define CPRESETMANAGER
#include "cpreset.hpp"
#include <memory>
#include <unordered_map>
#include <stdio.h>
#include "cgame.hpp"

class CPresetManager
{
private:
	CPresetManager(/* args */);
	~CPresetManager();
	static CPresetManager* managerInst;
	std::unordered_map<std::string, std::shared_ptr<CPreset> > presets;
public:
	static CPresetManager* getManager();
	bool ifPresetExcist(const std::string& descr)const{return presets.find(descr) != presets.end();};
	bool addPreset(const std::string&,std::shared_ptr<CPreset>);
	bool removePreset(const std::string&);
	bool updatePreset(const std::string&,std::function<void()>);
	bool runPreset(const std::string&);
	bool switchPresetTo(const std::string&);
	void exec();
	CPreset* getPreset(const std::string&);
	void setToInactive();
};



#endif