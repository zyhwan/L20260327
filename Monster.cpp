#include "Monster.h"
#include "Engine.h"
#include "World.h"
#include "ResourceManager.h"
#include "CollisionComponent.h"

AMonster::AMonster(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;

	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/monster.bmp", true, 255, 255, 255);
	SpriteComponent = CreateDefaultSubObject<USpriteComponent>("Sprite");
	SpriteComponent->ZOrder = 15;
	SpriteComponent->Image = TempResource.Image;
	SpriteComponent->Texture = TempResource.Texture;

	CollisionComponent = CreateDefaultSubObject<UCollisionComponent>("Collision");
	CollisionComponent->bIsGenerateHit = true;
	CollisionComponent->bIsGenerateOverlap = true;
}

AMonster::~AMonster()
{


}

void AMonster::Tick()
{
	__super::Tick();
	TotalTime += GEngine->GetDeltaSeconds();

	if (TotalTime >= ExecutionTime)
	{
		int Direction = rand() % 4;

		switch (Direction)
		{
		case 0:
			if (PrdictMove(X, Y - 1))
			{
				Y--;
			}
			break;
		case 1:
			if (PrdictMove(X, Y + 1))
			{
				Y++;
			}
			break;
		case 2:
			if (PrdictMove(X + 1, Y))
			{
				X++;
			}
			break;
		case 3:
			if (PrdictMove(X - 1, Y))
			{
				X--;
			}
			break;
		}

		TotalTime = 0.0f;
	}
}