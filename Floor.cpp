#include "Floor.h"

AFloor::AFloor(int InX, int InY, char InMesh, int InWeight)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = InWeight;
}

AFloor::~AFloor()
{
}
