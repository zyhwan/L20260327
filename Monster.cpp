#include "Monster.h"

AMonster::AMonster(int InX, int InY, char InMesh, int InWeight)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = InWeight;

	R = 255;
	G = 255;
	B = 0;

	Load("Data/monster.bmp");
}

AMonster::~AMonster()
{


}
