//
//  player.cpp
//  MyCppGame
//
//  Created by auto on 2017/7/9.
//
//

#include "player.hpp"
#include "HelloWorldScene.h"
#include "overScene.h"
bool Player::init() {
    this->setAnchorPoint(Point(0,0)) ;
    this->scheduleUpdate() ;
    return true ;
}

void Player::run(int direction) {
    //读取文件用的
    SpriteFrameCache * frameCache = SpriteFrameCache::getInstance() ;
    frameCache->addSpriteFramesWithFile("vanlio.plist","vanlio.png") ;
    //储存精灵帧的临时变量
    SpriteFrame *frame = NULL ;
    Vector<SpriteFrame * > frameListLeftRun ;
    Vector<SpriteFrame * > frameListRightRun ;
    Vector<SpriteFrame * > frameListLeftJump ;
    Vector<SpriteFrame * > frameListRightJump ;
    Vector<SpriteFrame * > frameList ;
    
    //创造精灵帧对象添加到列表中
    
    for (int i = 1; i <= 2; i++) {
            frame = frameCache->getSpriteFrameByName(StringUtils::format("runleft%d.png",i)) ;
            frameListLeftRun.pushBack(frame) ;
    }
//        frame = frameCache->getSpriteFrameByName(StringUtils::format("jumpleft.png")) ;
//        frameListLeftRun.pushBack(frame) ;
    
    for (int i = 1; i <= 2; i++) {
            frame = frameCache->getSpriteFrameByName(StringUtils::format("runright%d.png",i)) ;
            frameListRightRun.pushBack(frame) ;
    }
    frame = frameCache->getSpriteFrameByName("runleft1.png") ;
    frameListLeftJump.pushBack(frame) ;
    frame = frameCache->getSpriteFrameByName("jumpleft.png") ;
    frameListLeftJump.pushBack(frame) ;
    
    frame = frameCache ->getSpriteFrameByName("runright1.png") ;
    frameListRightJump.pushBack(frame) ;
    frame = frameCache->getSpriteFrameByName("jumpright.png") ;
    frameListRightJump.pushBack(frame) ;
    
    
//        frame = frameCache->getSpriteFrameByName(StringUtils::format("jump")) ;
//        frameList.pushBack(frame) ;
    if (direction==1&&this->m_controller->getIfOnFloor()==1) {
        frameList = frameListRightRun ;
    }else if (direction==-1&&this->m_controller->getIfOnFloor()==1){
        frameList = frameListLeftRun ;
    }else if(direction==1&&this->m_controller->getIfOnFloor()==0){
        frameList = frameListRightJump ;
    }else if (direction==-1&&this->m_controller->getIfOnFloor()==0){
        frameList = frameListLeftJump ;
    }else if (direction==0&&this->m_controller->getIfOnFloor()==0) {
        if (this->m_controller->getCurrentDriction()==1) {
            frameList = frameListRightJump ;
        }else if (this->m_controller->getCurrentDriction()==-1){
            frameList = frameListLeftJump ;
        }
    }
    
    //根据精灵帧对象创建动画对象
    Animation * animation = Animation::createWithSpriteFrames(frameList) ;
    animation->setLoops(-1) ; //循环播放
    animation->setDelayPerUnit(0.1f) ; //每帧播放间隔
    setRunning(1) ;
    //创建动画动作
    Animate * animate = Animate::create(animation) ;
    
    m_sprite->runAction(animate) ;
    setRunning(1) ;
}


void Player::setViewPointByPlayer() {
    if (m_sprite == NULL) {
        return ;
    }
    //获取地图？
    Layer * parent = (Layer*)getParent() ;
    
    //获取地图方块数量
    Size mapTiledNum = m_map->getMapSize() ;
    //获取单个方块的尺寸
    Size tiledSize = m_map->getTileSize() ;
    
    //设置地图的大小
    Size mapSize = Size( mapTiledNum.width * tiledSize.width,
                         mapTiledNum.height * tiledSize.height ) ;
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize() ;
    
    Point spritePos = getPosition() ;
    
    float x = std::max(spritePos.x,visibleSize.width/2) ;
    float y = std::max(spritePos.y,visibleSize.height/2) ;
    
    
    x = std::min(x,mapSize.width-visibleSize.width/2) ;
    y = std::min(y,mapSize.height-visibleSize.height/2) ;
    
    Point destPos = Point(x,y) ;
    
    Point centerPos = Point(visibleSize.width/2 ,visibleSize.height/2) ;
    
    Point viewPos = centerPos-destPos ;
    
    parent->setPosition(viewPos) ;
    
    
    
    
}


void Player::setTagPosition(int x,int y) {
    Size spritSize = m_sprite->getContentSize() ;
    Point dstPos = Point (x,y) ;
    
    Point tiledPos = tileCoordForPosition(dstPos) ;
    //判断前方是否有方块
    int tiledGid = block->getTileGIDAt(tiledPos) ;
    
    if (tiledGid!=0) {
        
        Value properties = m_map->getPropertiesForGID(tiledGid) ;
        Value prop1 = properties.asValueMap().at("isBlock") ;
        Value prop2 = properties.asValueMap().at("Kill") ;
        Value prop3 = properties.asValueMap().at("isWin") ;
        if (prop1.asInt()==1) {
            this->m_controller->setYSpeed(0) ;
            this->m_controller->setOnFloor(1) ;
            return ;
        }
        if (prop2.asInt()==1) {
            killVanLio() ;
        }
        if (prop3.asInt()==1) {
            win() ;
        }
        
    }
    
    //判断脚下是否有方块
    int DownGid = block->getTileGIDAt(Point(tiledPos.x,tiledPos.y+1)) ;
    if (DownGid==0) {
        this->m_controller->setOnFloor(0) ;
    }
    
    Entity::setTagPosition(x, y) ;
    
    setViewPointByPlayer() ;
}

void Player::setMap(TMXTiledMap * map) {
    this->m_map = map ;
    
    this->block = m_map->getLayer("block") ;
    this->block->setVisible(false) ;
}


void Player::update(float dt) {
    
    if (isLife==0) {
        HelloWorld * scene = HelloWorld::create() ;
        Director::getInstance()->pushScene(scene) ;

    }
    if (this->m_isRunning==0&&m_controller->getPushed()==1) {
        run(direction) ;
    }else if(this->m_isRunning==0&&m_controller->getPushed()==0){
        this->m_sprite->stopAllActions() ;
    }else if (this->m_isRunning==1&&m_controller->getPushed()==0){
        this->m_sprite->cleanup() ;
        setRunning(0) ;
    }else if (this->m_isRunning==1&&m_controller->getPushed()==1){
        log("播放动画") ;
    }else{
        log("错误") ;
    }
}

Point Player::tileCoordForPosition( Point pos) {
    Size mapTiledNum = m_map->getMapSize() ;
    Size tiledSize = m_map ->getTileSize() ;
    
    float x = (float)pos.x/tiledSize.width ;
    float y = (float)(mapTiledNum.height*tiledSize.height-pos.y)/tiledSize.height ;
    y=y+1.57 ;
    log("%f,%f",x,y) ;
    return Point(x,y) ;
}

void Player::win() {
    Director::getInstance()->pushScene(overScene::createScene()) ;
}
 void Player::isdied(float ft ){
    HelloWorld * scene = HelloWorld::create() ;
    Director::getInstance()->pushScene(scene) ;
}

