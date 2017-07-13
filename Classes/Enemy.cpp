//
//  Enemy.cpp
//  MyCppGame
//
//  Created by auto on 2017/7/11.
//
//

#include "Enemy.hpp"


bool Enemy::init() {
    this->scheduleUpdate() ;
    this->isBlocked = 0 ;
    return true ;
}
void Enemy::setMap(TMXTiledMap * map) {
    m_map = map ;
    block = map->getLayer("block") ;
}
void Enemy::update(float dt) {
    Point playerPos = m_player->getTagPosition() ;
    Point enemyPos = this ->getTagPosition() ;
    if (playerPos.x+14>= enemyPos.x&&playerPos.x<enemyPos.x) {
        if (playerPos.y<=enemyPos.y+14) {
            m_player->killVanLio() ;
        }
    }else if (enemyPos.x+14>=playerPos.x&&enemyPos.x<playerPos.x){
        if (playerPos.y<=enemyPos.y+14) {
            m_player->killVanLio() ;
        }
    }
}
Point Enemy::tileCoordForPosition( Point pos) {
    Size mapTiledNum = m_map->getMapSize() ;
    Size tiledSize = m_map ->getTileSize() ;
    
    float x = (float)pos.x/tiledSize.width ;
    float y = (float)(mapTiledNum.height*tiledSize.height-pos.y)/tiledSize.height ;
    y=y+1.57 ;
    log("%f,%f",x,y) ;
    return Point(x,y) ;
}

void Enemy::setTagPosition(int x,int y) {
    
    Size spritSize = m_sprite->getContentSize() ;
    Point dstPos = Point (x,y) ;
    
    Point tiledPos = tileCoordForPosition(dstPos) ;
    //判断前方是否有方块
    ///卡住了啊啊啊啊啊啊啊啊啊啊啊啊啊
    int tiledGid = block->getTileGIDAt(tiledPos) ;
    
    if (tiledGid!=0) {
        
        Value properties = m_map->getPropertiesForGID(tiledGid) ;
        Value prop1 = properties.asValueMap().at("isBlock") ;
        if (prop1.asInt()==1&&isBlocked==0) {
            if (this->m_controller->getDirection()==1) {
                this->m_controller->m_dirction = -1 ;
                isBlocked = 1 ;
                auto jumpby = JumpBy::create(0.5f, Point(-100,0), 0, 1) ;
                CallFunc * callFunc = CallFunc::create([&](){
                    isBlocked = 0 ;
                });
                auto actions = Sequence::create(jumpby,callFunc, NULL) ;
                this->runAction(actions) ;
            }else if (this->m_controller->getDirection()==-1){
                this->m_controller->m_dirction = 1 ;
                isBlocked = 1 ;
                auto jumpby = JumpBy::create(0.5f, Point(100,0), 0, 1) ;
                CallFunc * callFunc = CallFunc::create([&](){
                    isBlocked = 0 ;
                });
                auto actions = Sequence::create(jumpby,callFunc, NULL) ;
                this->runAction(actions) ;

//                Entity::setTagPosition(x+2, y) ;
            }
        }

    }
if (isBlocked==0) {
        Entity::setTagPosition(x, y) ;
    }
    
    
    
}


