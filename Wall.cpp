#include "Wall.h"

AWall::AWall(int InX, int InY, char InMesh, int InWeight)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = InWeight;

	R = 0;
	G = 255;
	B = 0;

	Load("Data/wall.bmp");
}

AWall::~AWall()
{
}
