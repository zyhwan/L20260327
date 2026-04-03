#include "Wall.h"
#include "ResourceManager.h"
#include "Engine.h"

AWall::AWall(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;

	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/wall.bmp");
	SpriteComponent = CreateDefaultSubObject<USpriteComponent>("Sprite");
	SpriteComponent->ZOrder = 5;
	SpriteComponent->Image = TempResource.Image;
	SpriteComponent->Texture = TempResource.Texture; 
}

AWall::~AWall()
{
}
