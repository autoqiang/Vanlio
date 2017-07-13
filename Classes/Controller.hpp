//
//  Controller.hpp
//  MyCppGame
//
//  Created by auto on 2017/7/9.
//
//

#ifndef Controller_hpp
#define Controller_hpp

#include "cocos2d.h"
#include "controllerListener.hpp" 
#define G 1

using namespace cocos2d ;
class Controller:public Node {
    
public:
    void setControllerListener(controllerListener * controllerListener) ;
    int getIfStopAction() ;
    int getDirection() ;
    int getPushed() ;
    void setYSpeed(int ySpeed) ;
    void setOnFloor(int onFloor) ;
    int getIfOnFloor();
    int getCurrentDriction() ;
    int m_dirction ;
protected:
    controllerListener* m_controllerListener ;
    int ifStopAction = 0 ;
    
    int m_tempDirction = 1 ;
    int isPushed ;
    int isOnFloor ;
    int m_iYSpeed;
    
};

#endif /* Controller_hpp */
