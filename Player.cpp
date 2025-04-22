#include<iostream>
#include "Player.h"
#include "Input.h"
APlayer::APlayer()
{
	Shape = 'P';
	Location.X = 1;
	Location.Y = 1;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	switch (toupper(UInput::KeyCode))
	{
	case 'W':
		AddActorWorldOffset(Fvector2D(0, -1));
		break;
	case 'A':
		AddActorWorldOffset(Fvector2D(-1, 0));
		break;
	case 'S':
		AddActorWorldOffset(Fvector2D(0, 1));
		break;
	case 'D':
		AddActorWorldOffset(Fvector2D(1, 0));
		break;
	default:
		break;
	}
}