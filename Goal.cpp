#include "Goal.h"
#include "Engine.h"
#include "ResourceManager.h"
#include "SpriteComponent.h"
#include "CollisionComponent.h"

AGoal::AGoal(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;

	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/goal.bmp", true, 255, 255, 255);
	SpriteComponent = CreateDefaultSubObject<USpriteComponent>("Sprite");
	SpriteComponent->ZOrder = 10;
	SpriteComponent->Image = TempResource.Image;
	SpriteComponent->Texture = TempResource.Texture;

	CollisionComponent = CreateDefaultSubObject<UCollisionComponent>("Collision");
	CollisionComponent->bIsGenerateHit = false;
	CollisionComponent->bIsGenerateOverlap = true;

	Name = "Goal";
}

AGoal::~AGoal()
{
}
