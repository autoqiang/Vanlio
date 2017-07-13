#include<iostream>
#include"cocos2d.h"
#include"mainMenuScene.h"
USING_NS_CC;
class loadScene : public Layer {
public:
	static Scene * createScene();
	virtual bool init();
	CREATE_FUNC(loadScene);
	void completeloading(float dt);
public:
	


};