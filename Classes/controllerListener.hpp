//
//  controllerListener.hpp
//  MyCppGame
//
//  Created by auto on 2017/7/9.
//
//

#ifndef controllerListener_hpp
#define controllerListener_hpp

#include "cocos2d.h"

using namespace cocos2d ;

class controllerListener {
    
public:
    virtual void setTagPosition (int x,int y) = 0 ;
    
    
    virtual Point getTagPosition() = 0 ;
    
    int direction ;
        
};

#endif /* controllerListener_hpp */
