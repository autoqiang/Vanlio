//
//  player.hpp
//  MyCppGame
//
//  Created by auto on 2017/7/9.
//
//

#ifndef player_hpp
#define player_hpp

#include "Entity.hpp"

class Player :public Entity {
    
public:
    CREATE_FUNC(Player) ;
    virtual bool init() ;
    void run(int direction) ;
    
    void setMap(TMXTiledMap * map) ;
    void setViewPointByPlayer() ;
    virtual void setTagPosition(int x,int y) ;
    
    virtual void update(float dt) ;
    void killVanLio() {
        isLife = 0 ;
    }
    int getIfLiving(){
        return isLife ;
    }
    void isdied(float ft) ;
    void win() ;
private:
    TMXTiledMap * m_map ;
    int isLife = 1;
    int isBlocked ;//是否被卡住
    TMXLayer * block ;
    Point tileCoordForPosition(Point pos) ;
};

#endif /* player_hpp */
