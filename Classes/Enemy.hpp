//
//  Enemy.hpp
//  MyCppGame
//
//  Created by auto on 2017/7/11.
//
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include "cocos2d.h" 
#include "Entity.hpp"
#include "player.hpp"
class Enemy:public Entity {
    
public:
    CREATE_FUNC(Enemy) ;
    virtual bool init() ;
    void setMap(TMXTiledMap * map) ;
    virtual void update(float dt) ;
    void setPlayer(Player * player) {
        m_player = player ;
    }
    virtual void setTagPosition(int x,int y) ;
private:
    int isBlocked ;
    Point tileCoordForPosition(Point pos) ;
    TMXTiledMap * m_map ;
    TMXLayer * block ;
    Player * m_player ;
};

#endif /* Enemy_hpp */
