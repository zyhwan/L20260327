#include <iostream>
#include "Actor.h"
#include "Engine.h"
#include "ResourceManager.h"


AActor::AActor(int InX, int InY, char InMesh, int InWeight)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = InWeight;

	R = 0;
	G = 0;
	B = 0;

	Texture = nullptr;
	Image = nullptr;
}

AActor::~AActor()
{
}

void AActor::BeginPlay()
{
}

void AActor::Tick()
{

}

void AActor::Render()
{
	int TileSize = 80;
	SDL_Rect DestinationRect = { X * TileSize, Y * TileSize, TileSize, TileSize };
	SDL_RenderCopy(GEngine->GetRenderer(), Texture, nullptr, &DestinationRect);
}

void AActor::SetActorLocation(int x, int y)
{
	X = x;
	Y = y;
}

