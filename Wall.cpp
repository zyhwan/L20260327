#include "Wall.h"

AWall::AWall(int InX, int InY, char InMesh, int InWeight)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	Weight = InWeight;
}

AWall::~AWall()
{
}
