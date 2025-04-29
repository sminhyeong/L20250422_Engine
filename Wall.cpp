#include "Wall.h"

AWall::AWall()
{
	Shape = '*';
	RenderOrder = 9;
	Color.a = 1;
	Color.r = 0;
	Color.g = 0;
	Color.b = 255;
	FileName = "wall.bmp";

	Load();


}

AWall::AWall(const Fvector2D& InVector) : AActor(InVector)
{
	Shape = '*';
	RenderOrder = 9;
	Color.a = 1;
	Color.r = 0;
	Color.g = 0;
	Color.b = 255;
	FileName = "wall.bmp";

	Load();

}

AWall::~AWall()
{
}
