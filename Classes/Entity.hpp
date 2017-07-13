//
//  Entity.hpp
//  MyCppGame
//
//  Created by auto on 2017/7/9.
//
//

#ifndef Entity_hpp
#define Entity_hpp

#include "cocos2d.h"
#include "controllerListener.hpp"
#include "Controller.hpp"

using namespace cocos2d ;
class Entity:public Node ,public controllerListener{
public:
    //绑定精灵对象
    
    void bindSprite(Sprite * sprite) ;
    
    void setController(Controller* controller) ;
    
    virtual void setTagPosition( int x ,int y ) ;
    
    virtual Point getTagPosition() ;
    void setRunning(int isRunning) ;
protected:
    
    Sprite * m_sprite ;
    Controller * m_controller ;
    int m_isRunning ;
};

#endif /* Entity_hpp */
