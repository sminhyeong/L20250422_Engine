#pragma once
#include "Vector2D.h"
class AActor
{
public :
	AActor();
	virtual ~AActor();

	void AddActorWorldOffset(Fvector2D offset);
	Fvector2D Location;

	virtual void Tick();
	virtual void Render();

protected:
	char Shape;

};

