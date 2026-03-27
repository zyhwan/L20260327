#include "Goal.h"

AGoal::AGoal(int InX, int InY, char InMesh, int InWeight)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	Weight = InWeight;
}

AGoal::~AGoal()
{
}
