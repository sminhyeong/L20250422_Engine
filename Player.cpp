#include<iostream>
#include "Player.h"
#include "Input.h"
#include "World.h"
#include "Engine.h"
#include "SDL3/SDL.h"

APlayer::APlayer()
{
	Shape = 'P';
	RenderOrder = 7;
	Color.r = 255;
	Color.g = 0;
	Color.b = 0;
	FileName = "player.bmp";
	ColorKey = { 255,0,255,255 };
	Load();

}

APlayer::APlayer(const Fvector2D& InVector) : AActor(InVector)
{
	Shape = 'P';
	RenderOrder = 7;
	Color.r = 255;
	Color.g = 0;
	Color.b = 0;
	FileName = "player.bmp";
	ColorKey = { 255,0,255,255 };
	Load();


}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	char filterShape = '*';
	if (GEninge->Event.type == SDL_EVENT_KEY_DOWN)
	{
		switch (GEninge->Event.key.key)
		{
		case SDLK_UP:
		case SDLK_W:
			if (CheckedCanMove(GetActor(0, -1, filterShape)))
				AddActorWorldOffset(Fvector2D(0, -1));
			break;
		case SDLK_A:
		case SDLK_LEFT:
			if (CheckedCanMove(GetActor(-1, 0, filterShape)))
				AddActorWorldOffset(Fvector2D(-1, 0));
			break;
		case SDLK_S:
		case SDLK_DOWN:
			if (CheckedCanMove(GetActor(0, 1, filterShape)))
				AddActorWorldOffset(Fvector2D(0, 1));
			break;
		case SDLK_D:
		case SDLK_RIGHT:
			if (CheckedCanMove(GetActor(1, 0, filterShape)))
				AddActorWorldOffset(Fvector2D(1, 0));
			break;
		default:
			break;
		}
	}
}

std::vector<AActor*> APlayer::GetActor(int X, int Y, char filter)
{

	std::vector<AActor*> FilterList;
	if (MyWorld)
	{
		std::vector<AActor*> Actors = MyWorld->GetActors(Location.X + X, Location.Y + Y);

		for (auto iter = Actors.begin(); iter != Actors.end(); iter++)
		{
			if ((*iter)->SameTag(filter))
			{
				FilterList.push_back(*iter);
			}
		}
	}
	return FilterList;
}

bool APlayer::CheckedCanMove(std::vector<AActor*> actors)
{
	if (actors.size() <= 0)
		return true;

	for (auto actor : actors)
	{
		if (actor->SameTag('*'))
			return false;
	}

	return true;
}
