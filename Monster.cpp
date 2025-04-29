#include "Monster.h"

AMonster::AMonster()
{
	Shape = 'M';
	RenderOrder = 6;
	Color.a = 1;
	Color.r = 0;
	Color.g = 255;
	Color.b = 0;
	FileName = "monster.bmp";
	Load();



}

AMonster::AMonster(const Fvector2D& InVector) : AActor(InVector)
{
	Shape = 'M';
	RenderOrder = 6;
	Color.a = 1;
	Color.r = 0;
	Color.g = 255;
	Color.b = 0;
	FileName = "monster.bmp";
	Load();


}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
}
