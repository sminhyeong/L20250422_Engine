#include "Goal.h"

AGoal::AGoal()
{
	Shape = 'G';
	RenderOrder = 8;
	Color.a = 1;
	Color.r = 255;
	Color.g = 0;
	Color.b = 255;
	FileName = "goal.bmp";
	Load();


}

AGoal::AGoal(const Fvector2D& InVector) : AActor(InVector)
{
	Shape = 'G';
	RenderOrder = 8;
	Color.a = 1;
	Color.r = 255;
	Color.g = 0;
	Color.b = 255;
	FileName = "goal.bmp";
	Load();

}

AGoal::~AGoal()
{
}
