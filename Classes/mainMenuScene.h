#ifndef mainMenuScene_h
#define mainMenuScene_h
#include<iostream>
#include"cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;

class mainMenuScene : public Layer {
public:
    static Scene * createScene(int died);
	virtual bool init();
	CREATE_FUNC(mainMenuScene);
	void startMenuCallback(Ref* pSender);
	void setMenuCallback(Ref* pSender);
	void helpMenuCallback(Ref* pSender);
	void exitMenuCallback(Ref* pSender);
    int isplayingMusic = 0;
    int canPlayMusic = 1 ;
    int canPlayEffce = 1 ;
    int getCanPlayMusic(){
        return canPlayMusic ;
    }
    int getCanPlayEffce(){
        return canPlayEffce ;
    }
};
#endif
