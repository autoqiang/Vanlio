//
//  Controller.cpp
//  MyCppGame
//
//  Created by auto on 2017/7/9.
//
//

#include "Controller.hpp"


void Controller::setControllerListener(controllerListener * controllerListener) {
    this->m_controllerListener = controllerListener ;
}
int Controller::getIfStopAction() {
    return ifStopAction ;
}
int Controller::getDirection(){
    return m_dirction ;
}

int Controller::getPushed() {
    return isPushed ;
}
void Controller::setYSpeed(int ySpeed) {
    this->m_iYSpeed =ySpeed ;
}
void Controller::setOnFloor(int onFloor) {
    this->isOnFloor = onFloor ;
}
int Controller::getIfOnFloor() {
    return isOnFloor ;
}

int Controller::getCurrentDriction() {
    return m_tempDirction ;
}
