//
//  leftAndRightMoveController.hpp
//  MyCppGame
//
//  Created by auto on 2017/7/9.
//
//

#ifndef leftAndRightMoveController_hpp
#define leftAndRightMoveController_hpp

#include "cocos2d.h" 
#include "Controller.hpp" 

using namespace cocos2d ;

class leftAndRightMoveController :public Controller {
    
public:
    CREATE_FUNC(leftAndRightMoveController) ;
    virtual bool init() ;
    virtual void update(float dt) ;
    
    void registerKeyboardEvent() ;
    
    void setiSpeed(int iSpeed) ;
    void setDirection(int dircetion) ;
    void jump() ;
private:
    int m_iSpeed ;
    
    
};

#endif /* leftAndRightMoveController_hpp */
