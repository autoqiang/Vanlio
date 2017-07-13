#include "mainMenuScene.h"
#include "TollgateScene.h"
#include "settingScene.h"
#include <string>
Scene* mainMenuScene::createScene(int died)
{
	auto scene = Scene::create();

	auto layer = mainMenuScene::create();
    
	scene->addChild(layer);

	return scene;
}

bool mainMenuScene::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Size WinSize = Director::getInstance()->getWinSize();

	auto sprite = Sprite::create("mainMenuScene.png");
    sprite->setScale(0.4) ;

	this->addChild(sprite);
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    
    Label * label = Label::createWithSystemFont("Vanlio", "fonts/Marker Felt.ttf", 48);
	label->setColor(Color3B(255, 0, 0));
	label->setPosition(Vec2(Vec2(WinSize.width / 2, WinSize.height * 3 / 4)));
	this->addChild(label);
	
	auto startItem = MenuItemImage::create(
		"start-up.png",
		"start-down.png",
		CC_CALLBACK_1(mainMenuScene::startMenuCallback, this));
	startItem->setPosition(Vec2(visibleSize.width / 2 + origin.x+100, visibleSize.height / 2 + origin.y+50));
    
    startItem->setScale(0.2) ;

	auto setItem = MenuItemImage::create(
		"settingup.png",
		"settingdown.png",
		CC_CALLBACK_1(mainMenuScene::setMenuCallback, this));
	setItem->setPosition(Vec2(visibleSize.width / 2 + origin.x+100, visibleSize.height / 2 + origin.y));
    
    setItem->setScale(0.2) ;
	auto helpItem = MenuItemImage::create(
		"help-up.png",
		"help-down.png",
		CC_CALLBACK_1(mainMenuScene::helpMenuCallback, this));
	helpItem->setPosition(Vec2(visibleSize.width / 2 + origin.x+100, visibleSize.height / 2 + origin.y-50));

    helpItem->setScale(0.2) ;
	auto exitItem = MenuItemImage::create(
		"ok-up.png",
		"ok-down.png",
		CC_CALLBACK_1(mainMenuScene::exitMenuCallback, this));
	exitItem->setPosition(Vec2(visibleSize.width / 2 + origin.x+100, visibleSize.height / 2 + origin.y - 100));
    
    exitItem->setScale(0.2) ;

	auto menu = Menu::create(startItem, setItem, helpItem, exitItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
    auto audioengine = SimpleAudioEngine::getInstance();
    audioengine->preloadBackgroundMusic("backgroundmusic.mp3");
    if (isplayingMusic==0) {
        audioengine->playBackgroundMusic("backgroundmusic.mp3", true);
        isplayingMusic = 1 ;
    }
	return true;
}



void mainMenuScene::startMenuCallback(Ref * peSender)
{
	Scene * gamescene = TollgateScene::createScene();
	Director::getInstance()->pushScene(gamescene);
}

void mainMenuScene::setMenuCallback(Ref* pSender)
{
    
    Setting * setting = Setting::create() ;
    setting->bindMainScene(this) ;
    setting->loadItems() ;
    Scene * nextScene = Scene::create() ;
    nextScene->addChild(setting) ;
    Director::getInstance()->pushScene(nextScene) ;
    
}

void  mainMenuScene::helpMenuCallback(Ref* pSender)
{

}

void mainMenuScene::exitMenuCallback(Ref* pSender)
{
	Director::getInstance()->end();
}


