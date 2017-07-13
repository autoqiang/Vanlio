//
//  leftAndRightMoveController.cpp
//  MyCppGame
//
//  Created by auto on 2017/7/9.
//
//

#include "leftAndRightMoveController.hpp"


void leftAndRightMoveController::registerKeyboardEvent(){
    auto listener = EventListenerKeyboard::create() ;
    
    listener->onKeyPressed = [this](EventKeyboard::KeyCode code ,Event *event){
        log("key with keycode %d pressed",code) ;
        this->isPushed = 1 ;
        if ((int)code == 124 || (int)code == 26) {
            m_dirction = m_dirction-1;
            this->m_controllerListener->direction = m_dirction ;
        }
        else if ((int)code == 127 || (int)code == 27) {
            m_dirction = m_dirction+1 ;
            this->m_controllerListener->direction = m_dirction ;
        }
        else if ((int)code == 146 || (int)code == 28)  {
            if (isOnFloor) {
                this->jump() ;
            }
            
        }
    } ;
    listener->onKeyReleased = [this](EventKeyboard::KeyCode code,Event * event) {
        this ->isPushed = 0 ;
        if ((int)code == 124 || (int)code == 26) {
            m_dirction = m_dirction+1;
            this->m_controllerListener->direction = m_dirction ;
            this->m_tempDirction = -1 ;
        }
        else if ((int)code == 127 || (int)code == 27) {
            m_dirction = m_dirction-1 ;
            this->m_controllerListener->direction = m_dirction ;
            this->m_tempDirction = 1 ;
        }

    } ;
    auto dispatcher = Director::getInstance()->getEventDispatcher() ;
    dispatcher->addEventListenerWithFixedPriority(listener, 1) ;
    
}

bool leftAndRightMoveController::init(){
    Controller::init() ;
    this->m_iSpeed = 0 ;
    this->m_dirction = 0 ;
    this->m_iYSpeed = 0 ;
    registerKeyboardEvent() ;
    
    
    this->scheduleUpdate() ;
    return true ;
    
}

void leftAndRightMoveController::update(float dt) {
    if (m_controllerListener ==NULL) {
        return ;
    }
    if (m_dirction==0) {
        ifStopAction = 1 ;
    }else{
        ifStopAction = 0 ;
    }
    Point pos = m_controllerListener->getTagPosition() ;
    pos.x += m_iSpeed*m_dirction ;
    pos.y +=m_iYSpeed ;
    m_controllerListener->setTagPosition(pos.x, pos.y) ;
    if (!isOnFloor) {
        m_iYSpeed-=G ;
    }
    
    

}

void leftAndRightMoveController::setiSpeed(int iSpeed) {
    m_iSpeed = iSpeed ;
}

void leftAndRightMoveController::setDirection(int direction) {
    m_dirction = direction ;
}

void leftAndRightMoveController::jump() {
    this->m_iYSpeed = 10 ;
    isOnFloor = 0 ;
}
