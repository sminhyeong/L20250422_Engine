#pragma once
#include <vector>
#include <string>
#include "Vector2D.h"
#include "SDL3/SDL.h"

class UWorld;

class AActor
{
public :
	AActor();
	AActor(const Fvector2D& InVector);
	virtual ~AActor();
	void SetMyWorld(UWorld *myWorld);
	void AddActorWorldOffset(Fvector2D offset);
	Fvector2D Location;

	static bool Compare(const AActor* A, const AActor*B);

	virtual void Tick();
	virtual void Render();
	virtual bool SameTag(char Tag);
	int GetRenderOrder() const;
	char Shape;

	SDL_Color Color;
	SDL_Color ColorKey;

	std::string FileName;
	SDL_Surface* Surface;
	SDL_Texture* textue;
	void Load();

protected:
	int RenderOrder;
	UWorld *MyWorld;
	virtual std::vector<AActor*>GetActor(int X, int Y, char filter);
	virtual bool CheckedCanMove(std::vector<AActor*> actors);
};

class ActorCompareByRenderOrder
{
public :
	bool operator()(const AActor* A, const AActor* B)
	{
		return A->GetRenderOrder() > B->GetRenderOrder();
	}
};