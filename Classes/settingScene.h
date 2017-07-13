//
//  settingScence.hpp
//  MyCppGame
//
//  Created by auto on 2017/7/7.
//
//

#ifndef settingScene_h
#define settingScene_h
#include "mainMenuScene.h"
#include "cocos2d.h"

class Setting : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* createScene();
    
    virtual Setting*  create(mainMenuScene * mainScene) {
        Node::create() ;
        bindMainScene(mainScene) ;
        init() ;
    }
    virtual bool init();
    void loadItems() ;
    
    void menuSoundToggleCallback(cocos2d::Ref* pSender);
    void menuMusicToggleCallback(cocos2d::Ref* pSender);
    void menuOkCallback(cocos2d::Ref* pSender);
    
    void bindMainScene(mainMenuScene * Scene){
        mainScene = Scene ;
    }
    CREATE_FUNC(Setting);
    mainMenuScene * mainScene ;
};

#endif // __Setting_SCENE_H__
