#include <iostream>
#include "Actor.h"
#include "Engine.h"

AActor::AActor(int InX, int InY, char InMesh, int InWeight)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = InWeight;

	R = 0;
	G = 0;
	B = 0;
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
	GEngine->Render(X, Y, Mesh);
	GEngine->Render(X, Y, R, G, B);
}

void AActor::SetActorLocation(int x, int y)
{
	X = x;
	Y = y;
}
