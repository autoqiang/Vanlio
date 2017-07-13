//
//  simpleMoveController.cpp
//  MyCppGame
//
//  Created by auto on 2017/7/9.
//
//

#include "simpleMoveController.hpp"



bool simpleMoveController::init() {
    this->m_iSpeed = 0 ;
    this->m_dirction = 0 ;
    //启动定时器回调
    this->scheduleUpdate() ;
    
    return true ;
}

void simpleMoveController::update(float dt ) {
    if (m_controllerListener ==NULL) {
        return ;
    }
    
    Point pos = m_controllerListener->getTagPosition() ;
    if (m_dirction == 1) {
        pos.x += m_iSpeed ;
        m_controllerListener->setTagPosition(pos.x, pos.y) ;
    }else if(m_dirction == -1) {
        pos.x -= m_iSpeed ;
        m_controllerListener->setTagPosition(pos.x, pos.y) ;
    }
    
}

void simpleMoveController::setiSpeed(int iSpeed) {
    this ->m_iSpeed = iSpeed ;
}
void simpleMoveController::setDirection(int direction){
    this->m_dirction = direction ;
}
