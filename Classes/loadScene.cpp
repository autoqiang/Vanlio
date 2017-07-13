#include"loadScene.h"
Scene* loadScene::createScene()
{
	auto scene = Scene::create();

	auto layer = loadScene::create();

	scene->addChild(layer);

	return scene;
}
bool loadScene::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("loading.png");

	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(sprite);

	scheduleOnce(CC_SCHEDULE_SELECTOR(loadScene::completeloading), 2.0);

	return true;
}

void loadScene::completeloading(float dt)
{
	Scene *mainmenu = mainMenuScene::createScene(-1);
	Director::getInstance()->replaceScene(mainmenu);
}
