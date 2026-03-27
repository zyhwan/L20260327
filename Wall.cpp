#include "Wall.h"

AWall::AWall(int InX, int InY, char InMesh, int InWeight)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = InWeight;
}

AWall::~AWall()
{
}
