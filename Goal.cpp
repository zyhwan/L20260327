#include "Goal.h"

AGoal::AGoal(int InX, int InY, char InMesh, int InWeight)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = InWeight;

	R = 0;
	G = 0;
	B = 255;
	Load("Data/goal.bmp");
}

AGoal::~AGoal()
{
}
