#include "cpresetmanager.hpp"
#include <thread>

CPresetManager* CPresetManager::managerInst;

CPresetManager::CPresetManager(/* args */)
{
    printf("PresetManger created\n");
}

CPresetManager::~CPresetManager()
{
    printf("PresetManger deleted\n");
    presets.clear();
}

CPresetManager* CPresetManager::getManager(){
    if(!managerInst){
        managerInst = new CPresetManager();
        struct Eraser
        {
            ~Eraser(){delete managerInst; };
        };
        static Eraser eraser;
    }
    return managerInst;
}

bool CPresetManager::addPreset(const std::string& descr, std::shared_ptr<CPreset> preset){
    if(ifPresetExcist(descr)){
        perror("Error! Preset already excist...");
        return false;
    }
    presets[descr] = std::move(preset);
    return true;
}

bool CPresetManager::removePreset(const std::string& descr){
    if(!ifPresetExcist(descr)){
        perror("Error! The preset doesn't excist...");
        return false;
    }
    presets.erase(descr);
    return true;
}

bool CPresetManager::updatePreset(const std::string& descr, std::function<void()> func){
    if(!ifPresetExcist(descr)){
        perror("Error! The preset doesn't excist...");
        return false;
    }
    presets.find(descr)->second->createPreset(func);
    return true;
}

bool CPresetManager::runPreset(const std::string& descr){
    if(!ifPresetExcist(descr)){
        perror("Error! The preset doesn't excist...");
        return false;
    }
    CGame::getGameInst()->changeGameProcess(true);
    presets.find(descr)->second->runPreset();
    return true;
}

bool CPresetManager::switchPresetTo(const std::string& descr){
    if(!ifPresetExcist(descr)){
        perror("Error! The preset doesn't excist...");
        return false;
    }
    CGame::getGameInst()->ereseGameObjects();
    CGame::getGameInst()->changeGameProcess(false);
    setToInactive();
    getPreset(descr)->setState(PresetStates::atctive);
    return true;
}

void CPresetManager::exec(){
    CPreset* activePreset = nullptr;
    do
    {
        for(auto preset : presets){
            if(preset.second->getState() == PresetStates::atctive){
                activePreset = preset.second.get();
                break;
            }
            activePreset = nullptr;
        }
        activePreset->runPreset();
    } while (activePreset);
}

CPreset* CPresetManager::getPreset(const std::string& descr){
    if(!ifPresetExcist(descr)){
        perror("Error! The preset doesn't excist...");
        return nullptr;
    }
    return presets.find(descr)->second.get();
}

void CPresetManager::setToInactive(){
    for(auto preset : presets){
        preset.second->setState(PresetStates::inactive);
    }
}
