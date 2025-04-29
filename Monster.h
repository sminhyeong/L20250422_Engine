#pragma once
#include"Actor.h"
class AMonster : public AActor
{
public:
	AMonster();
	AMonster(const Fvector2D& InVector);
	virtual ~AMonster();
	virtual void Tick() override;
};

