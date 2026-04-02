#include "Wall.h"
#include "ResourceManager.h"
#include "Engine.h"

AWall::AWall(int InX, int InY, char InMesh, int InWeight)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = InWeight;

	R = 0;
	G = 255;
	B = 0;

	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/wall.bmp");
	Image = TempResource.Image;
	Texture = TempResource.Texture;
}

AWall::~AWall()
{
}
