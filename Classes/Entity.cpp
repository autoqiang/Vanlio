//
//  Entity.cpp
//  MyCppGame
//
//  Created by auto on 2017/7/9.
//
//

#include "Entity.hpp"

void Entity::bindSprite(Sprite *sprite) {
    m_sprite = sprite ;
    this->addChild(m_sprite) ;
}

void Entity::setController(Controller* controller) {
    m_controller = controller ;
    m_controller->setControllerListener(this) ;
}

void Entity::setTagPosition(int x, int y) {
    setPosition(Point(x,y)) ;
}

Point Entity::getTagPosition() {
    return getPosition() ;
}
void Entity::setRunning(int isRunning){
    m_isRunning = isRunning ;
}
