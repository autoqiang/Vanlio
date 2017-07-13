//
//  TollgateScene.hpp
//  MyCppGame
//
//  Created by auto on 2017/7/9.
//
//

#ifndef TollgateScene_h
#define TollgateScene_h 

#include "cocos2d.h"

using namespace cocos2d ;

class TollgateScene:public Layer {
public:
    static Scene * createScene() ;
    CREATE_FUNC(TollgateScene) ;
    virtual bool init () ;
    void addPlayer(TMXTiledMap *map) ;
        
    
};
#endif /* TollgateScene_hpp */
