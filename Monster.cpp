#include "Monster.h"
#include "Engine.h"
#include "ResourceManager.h"

AMonster::AMonster(int InX, int InY, char InMesh, int InWeight)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = InWeight;

	R = 255;
	G = 255;
	B = 0;

	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/monster.bmp", true, 255, 255, 255);
	Image = TempResource.Image;
	Texture = TempResource.Texture;
}

AMonster::~AMonster()
{


}

void AMonster::Tick()
{
	__super::Tick();
	__super::Tick();
	TotalTime += GEngine->GetDeltaSeconds();

	if (TotalTime >= ExecutionTime)
	{
		int Direction = rand() % 4;

		switch (Direction)
		{
		case 0:
			if (Y > 1)
			{
				Y--;
			}
			break;
		case 1:
			if (Y < 8)
			{
				Y++;
			}
			break;
		case 2:
			if (X < 8)
			{
				X++;
			}
			break;
		case 3:
			if (X > 1)
			{
				X--;
			}
			break;
		}

		TotalTime = 0.0f;
	}
}
