//
//  Cloud.hpp
//  MyCppGame
//
//  Created by auto on 2017/7/11.
//
//

#ifndef Cloud_hpp
#define Cloud_hpp

#include "cocos2d.h"
#include "Entity.hpp"
#include "player.hpp"

class Cloud:public Entity {
public:
    CREATE_FUNC(Cloud) ;
    virtual bool init() ;
    virtual void update(float dt) ;
    void setMap(TMXTiledMap * map) ;
    void setPlayer(Player * player) {
        m_player = player ;
    }
    void bindCloud2(Sprite * cloud2) {
        m_cloud =cloud2 ;
    }
private:
    Player * m_player ;
    TMXTiledMap * m_map ;
    Point tileCoordForPosition(Point pos) ;
    Sprite * m_cloud ;
};

#endif /* Cloud_hpp */
