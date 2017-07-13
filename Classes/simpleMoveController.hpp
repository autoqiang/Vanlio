//
//  simpleMoveController.hpp
//  MyCppGame
//
//  Created by auto on 2017/7/9.
//
//

#ifndef simpleMoveController_hpp
#define simpleMoveController_hpp

#include "cocos2d.h" 
#include "Controller.hpp"

using namespace cocos2d ;

class simpleMoveController:public Controller {
    
public:
    //用于为特定的类添加一个构造函数 应该仅有需要实体化的类要写这个宏
    CREATE_FUNC(simpleMoveController) ;
    virtual bool init() ;
    virtual void update(float dt) ;
    
    
    void setiSpeed(int iSpeed) ;
    void setDirection(int direction) ;
private:
    int m_iSpeed ;
    
    
};

#endif /* simpleMoveController_hpp */
