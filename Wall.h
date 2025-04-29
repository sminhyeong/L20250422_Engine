#pragma once
#include "Actor.h"
class AWall :
    public AActor
{
public :
    AWall();
    AWall(const Fvector2D& InVector);
    virtual ~AWall();
};

