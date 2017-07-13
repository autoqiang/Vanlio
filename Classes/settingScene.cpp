//
//  settingScence.cpp
//  MyCppGame
//
//  Created by auto on 2017/7/7.
//
//

#include "settingScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;

Scene* Setting::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Setting::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Setting::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
        return true;
}
void Setting::loadItems() {
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Sprite *bg = Sprite::create("settingScene.png");
    
    // position the label on the center of the screen
    bg->setPosition(Vec2(origin.x + visibleSize.width/2,
                         origin.y + visibleSize.height /2));
    bg->setScale(0.4)  ;
    this->addChild(bg);
    
    //音效
    auto soundOnMenuItem = MenuItemImage::create(
                                                 "on.png",
                                                 "on.png");
    auto soundOffMenuItem = MenuItemImage::create(
                                                  "off.png",
                                                  "off.png");
    
    
    //音乐
    auto musicOnMenuItem  = MenuItemImage::create(
                                                  "on.png",
                                                  "on.png");
    auto musicOffMenuItem  = MenuItemImage::create(
                                                   "off.png",
                                                   "off.png");
    
    MenuItemToggle  *soundToggleMenuItem ;
    if (this->mainScene->getCanPlayEffce()==1) {
        soundToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(Setting::menuSoundToggleCallback, this),
                                                                 soundOnMenuItem,
                                                                 soundOffMenuItem,
                                                                 NULL);
        soundToggleMenuItem->setScale(0.2) ;
        soundToggleMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(350, 115)));
        
        
    }else if(this->mainScene->getCanPlayEffce()==0){
        soundToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(Setting::menuSoundToggleCallback, this),
                                                                 soundOffMenuItem,
                                                                 soundOnMenuItem,
                                                                 NULL);
        soundToggleMenuItem->setScale(0.2) ;
        soundToggleMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(350, 115)));
        
        
    }
    MenuItemToggle * musicToggleMenuItem ;
    if (this->mainScene->getCanPlayMusic()==1) {
        musicToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(Setting::menuMusicToggleCallback, this),
                                                                 musicOnMenuItem,
                                                                 musicOffMenuItem,
                                                                 NULL );
        musicToggleMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(350, 180)));
        musicToggleMenuItem->setScale(0.2) ;
        
    }else if (this->mainScene->getCanPlayMusic()==0){
        musicToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(Setting::menuMusicToggleCallback, this),
                                                                 musicOffMenuItem,
                                                                 musicOnMenuItem,
                                                                 NULL );
        musicToggleMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(350, 180)));
        musicToggleMenuItem->setScale(0.2) ;
        
    }
    //Ok按钮
    auto okMenuItem  = MenuItemImage::create(
                                             "ok-down.png",
                                             "ok-up.png",
                                             CC_CALLBACK_1(Setting::menuOkCallback, this));
    
    okMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(230, 250)));
    okMenuItem->setScale(0.2) ;
    Menu* mn = Menu::create(soundToggleMenuItem, musicToggleMenuItem,okMenuItem, NULL);
    mn->setPosition(Vec2::ZERO);
    this->addChild(mn);
    

}

void Setting::menuOkCallback(Ref* pSender)
{
    Director::getInstance()->popScene();
}

void Setting::menuSoundToggleCallback(Ref* pSender)
{
    if (this->mainScene->getCanPlayEffce() == 1) {
        this->mainScene->canPlayEffce = 0 ;
//        SimpleAudioEngine::getInstance()->pauseAllEffects() ;
    }else if(this->mainScene->getCanPlayEffce() == 0 ){
        this->mainScene->canPlayEffce= 1 ;
//        SimpleAudioEngine::getInstance()->play
    }

}


void Setting::menuMusicToggleCallback(Ref* pSender)
{
    if (this->mainScene->getCanPlayMusic() == 1) {
        this->mainScene->canPlayMusic = 0 ;
        SimpleAudioEngine::getInstance()->pauseBackgroundMusic() ;
    }else if(this->mainScene->getCanPlayMusic() == 0 ){
        this->mainScene->canPlayMusic = 1 ;
        SimpleAudioEngine::getInstance()->playBackgroundMusic("backgroundmusic.mp3", true);

    }
}
