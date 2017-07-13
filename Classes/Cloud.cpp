//
//  Cloud.cpp
//  MyCppGame
//
//  Created by auto on 2017/7/11.
//
//

#include "Cloud.hpp"
bool Cloud::init() {
    this->scheduleUpdate() ;
    return true ;
}

void Cloud::update(float dt) {
    
    Point playerPos = m_player->getTagPosition() ;
    Point enemyPos = this ->getTagPosition() ;
    if (playerPos.x+14>= enemyPos.x&&playerPos.x<enemyPos.x) {
        if ((playerPos.y<=enemyPos.y+14)&&playerPos.y>=enemyPos.y) {
        Sprite* cloudnew = Sprite::create("cloud2.png") ;
            this->bindSprite(cloudnew) ;
        m_player->killVanLio() ;
        }
    }
    if (enemyPos.x+14>=playerPos.x&&enemyPos.x<playerPos.x){
        if ((playerPos.y<=enemyPos.y+14)&&playerPos.y>=enemyPos.y) {
            Sprite* cloudnew = Sprite::create("cloud2.png") ;
            this->bindSprite(cloudnew) ;
            //等两秒
            m_player->killVanLio() ;
        }
    }
}
void Cloud::setMap(TMXTiledMap * map) {
    m_map = map ;
}
Point Cloud::tileCoordForPosition(Point pos) {
    Size mapTiledNum = m_map->getMapSize() ;
    Size tiledSize = m_map ->getTileSize() ;
    
    float x = (float)pos.x/tiledSize.width ;
    float y = (float)(mapTiledNum.height*tiledSize.height-pos.y)/tiledSize.height ;
    y=y+1.57 ;
    log("%f,%f",x,y) ;
    return Point(x,y) ;

}
