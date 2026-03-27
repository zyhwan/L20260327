#include "Monster.h"

AMonster::AMonster(int InX, int InY, char InMesh, int InWeight)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = InWeight;
}

AMonster::~AMonster()
{


}
