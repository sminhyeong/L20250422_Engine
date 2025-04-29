#include "Ground.h"

AGround::AGround()
{
	Shape = ' ';
	RenderOrder = 10;
	Color.a = 1;
	Color.r = 255;
	Color.g = 255;
	Color.b = 255;
	FileName = "floor.bmp";
	Load();


}

AGround::AGround(const Fvector2D& InVector) : AActor(InVector)
{
	Shape = ' ';
	RenderOrder = 10;
	Color.a = 1;
	Color.r = 255;
	Color.g = 255;
	Color.b = 255;
	FileName = "floor.bmp";
	Load();


}

AGround::~AGround()
{
}
