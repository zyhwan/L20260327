#include "Floor.h"

AFloor::AFloor(int InX, int InY, char InMesh, int InWeight)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = InWeight;

	R = 0;
	G = 0;
	B = 0;
}

AFloor::~AFloor()
{
}
