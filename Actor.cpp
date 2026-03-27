#include <iostream>
#include "Actor.h"
#include "Engine.h"

AActor::AActor(int InX, int InY, char InMesh, int InWeight)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = InWeight;
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
}

void AActor::SetActorLocation(int x, int y)
{
	X = x;
	Y = y;
}
