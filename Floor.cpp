#include "Floor.h"
#include "Engine.h"
#include "ResourceManager.h"
#include "SpriteComponent.h"

AFloor::AFloor(int InX, int InY)
{
	X = InX;
	Y = InY;

	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/floor.bmp");
	SpriteComponent = CreateDefaultSubObject<USpriteComponent>("Sprite");
	SpriteComponent->ZOrder = 0;
	SpriteComponent->Image = TempResource.Image;
	SpriteComponent->Texture = TempResource.Texture;

	Name = "Floor";
}

AFloor::~AFloor()
{
}
