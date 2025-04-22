#include <iostream>
#include <windows.h>
#include "Actor.h"

AActor::AActor()
{
	Shape = '\0';
}

AActor::~AActor()
{
}

void AActor::AddActorWorldOffset(Fvector2D offset)
{
	Location.X += offset.X;
	Location.Y += offset.Y;

}

void AActor::Tick()
{
}

void AActor::Render()
{
	COORD Position = {(SHORT)Location.X, (SHORT)Location.Y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
	std::cout << Shape;
}