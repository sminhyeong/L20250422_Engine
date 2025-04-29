#include <iostream>
#include <windows.h>
#include "Actor.h"
#include "World.h"
#include "Renderer.h"


AActor::AActor()
{
	ColorKey = { 255,255,255,255 };
}

AActor::AActor(const Fvector2D& InVector)
{
	Location = Fvector2D(InVector.X, InVector.Y);
	ColorKey = { 255,255,255,255 };
}

AActor::~AActor()
{
}

void AActor::SetMyWorld(UWorld* myWorld)
{
	MyWorld = myWorld;
}

void AActor::AddActorWorldOffset(Fvector2D offset)
{
	Location.X += offset.X;
	Location.Y += offset.Y;

}

bool AActor::Compare(const AActor* A, const AActor* B)
{
	return A->GetRenderOrder() > B->GetRenderOrder();
}

void AActor::Tick()
{
}
void AActor::Load()
{
	if (FileName.size() > 0)
	{
		std::string Temp = "./Data/" + FileName;
		Surface = SDL_LoadBMP(Temp.c_str());
		const SDL_PixelFormatDetails* pixelDatails = SDL_GetPixelFormatDetails(Surface->format);
		SDL_SetSurfaceColorKey(Surface, true, SDL_MapRGB(pixelDatails, nullptr,ColorKey.r, ColorKey.g, ColorKey.b));
	}
	textue = SDL_CreateTextureFromSurface(URenderer::GetInstance()->Renderer, Surface);

}
void AActor::Render()
{
	//더블 버퍼링 사용한 방식
	URenderer::GetInstance()->Render(this);
	/*COORD Position = {(SHORT)Location.X, (SHORT)Location.Y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
	std::cout << Shape;*/
}

bool AActor::SameTag(char Tag)
{
	return this->Shape == Tag;
}

int AActor::GetRenderOrder() const
{
	return RenderOrder;
}

std::vector<AActor*>AActor::GetActor(int X, int Y, char filter)
{
	std::vector<AActor*> actors;
	return actors;
}

bool AActor::CheckedCanMove(std::vector<AActor*> actors)
{
	return false;
}