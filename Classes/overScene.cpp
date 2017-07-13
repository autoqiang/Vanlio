#include "overScene.h"
#include "mainMenuScene.h"
USING_NS_CC;

Scene* overScene::createScene()
{
    return overScene::create();
}

// on "init" you need to initialize your instance
bool overScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "ok-up.png",
                                           "ok-down.png",
                                           CC_CALLBACK_1(overScene::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(235,100)) ;
    closeItem->setScale(0.2) ;
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("You Win", "fonts/Marker Felt.ttf", 24);
    label->setColor(Color3B(255, 0, 0));
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height-100));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("bg.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}


void overScene::menuCloseCallback(Ref* pSender)
{
    mainMenuScene * mainScene = mainMenuScene::create() ;
    mainScene->isplayingMusic = 1 ;
    Scene * next = Scene::create() ;
    next->addChild(mainScene) ;
    Director::getInstance()->pushScene(next) ;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
