//
//  TollgateScene.cpp
//  MyCppGame
//
//  Created by auto on 2017/7/9.
//
//

#include "TollgateScene.h"
#include "player.hpp"
#include "Enemy.hpp"
#include "Cloud.hpp"
#include "simpleMoveController.hpp"

#include "leftAndRightMoveController.hpp"

Scene * TollgateScene::createScene() {
    auto scene = Scene::create() ;
    auto layer = TollgateScene::create() ;
    scene->addChild(layer) ;
    return scene ;
}

bool TollgateScene::init() {
    if (!Layer::init()) {
        return false ;
    }
    TMXTiledMap * map = TMXTiledMap::create("level01.tmx") ;
    this->addChild(map) ;
    
    
    addPlayer(map) ;
    
    return true ;
}

void TollgateScene::addPlayer(TMXTiledMap *map){
    TMXObjectGroup *objGroup = map->getObjectGroup("objects") ;
    
    
    //ValueMap可以当成map  key值必须为string value必须为Value对象 
    ValueMap playerPointMap = objGroup -> getObject("BirthPoint") ;
    ValueMap cloudPointMap = objGroup -> getObject("Cloud") ;
    ValueMap enemyPointMap = objGroup -> getObject("Enemy") ;
    float playerX = playerPointMap.at("x").asFloat() ;
    float playerY = playerPointMap.at("y").asFloat() ;
    float cloudX = cloudPointMap.at("x").asFloat() ;
    float cloudY = cloudPointMap.at("y").asFloat() ;
    float enemyX = enemyPointMap.at("x").asFloat() ;
    float enemyY = enemyPointMap.at("y").asFloat() ;
//    ValueVector enemyVector = objGroup ->getObjects() ;
    
    leftAndRightMoveController * lrcontroller = leftAndRightMoveController::create() ;
    lrcontroller->setiSpeed(3) ;
    simpleMoveController * Spcontroller = simpleMoveController::create() ;
    Spcontroller->setiSpeed(1) ;
    Spcontroller->setDirection(1) ;
    //加入场景之后才能让update调用
    this->addChild(lrcontroller, 0, 111) ;
    this->addChild(Spcontroller,0,111) ;
//    Size visibleSize = Director::getInstance()->getVisibleSize() ;
    
    
    Sprite * playerSprite = Sprite::create("player.png") ;
    Player * player = Player::create() ;
    player->bindSprite(playerSprite) ;
    player->setController(lrcontroller) ;
    player->setMap(map) ;
    
    
    Sprite * Cloud1 = Sprite::create("cloud1.png") ;
    Sprite * Cloud2 = Sprite::create("cloud2.png") ;
    Cloud2->setVisible(false) ;
    Cloud * cloud = Cloud::create() ;
    cloud->bindSprite(Cloud1) ;
    cloud->bindCloud2(Cloud2) ;
    cloud->setMap(map) ;
    cloud->setPlayer(player) ;
    cloud->setPosition(Point(cloudX,cloudY)) ;
    
    map->addChild(cloud,10,1) ;

    
    
    
    Sprite * enemySprite = Sprite::create("enemy.png") ;
    Enemy * enemy = Enemy::create() ;
    enemy->bindSprite(enemySprite) ;
    enemy->setController(Spcontroller) ;
    enemy->setPosition(Point(enemyX,enemyY)) ;
    enemy->setMap(map) ;
    enemy->setPlayer(player) ;
            
    map->addChild(enemy,10,1) ;
    
    

//    player->run(controller->getDirection()) ;
    
    
    player->setPosition(Point(playerX,playerY)) ;
    map->addChild(player,100,1) ;
}


