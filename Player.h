#pragma once
#include "Actor.h"

class APlayer : public AActor
{
public :
	APlayer();
	APlayer(const Fvector2D& InVector);
	virtual ~APlayer();
	virtual void Tick() override;
protected:
	virtual std::vector<AActor*> GetActor(int X, int Y, char filter) override;
	virtual bool CheckedCanMove(std::vector<AActor*> actor) override;
};

