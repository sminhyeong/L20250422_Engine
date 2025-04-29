#pragma once
#include "Actor.h"


class AGoal : public AActor
{
public :
	AGoal();
	AGoal(const Fvector2D& InVector);
	virtual ~AGoal();
};

