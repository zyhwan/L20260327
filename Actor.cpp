#include <iostream>
#include "Actor.h"
#include "Engine.h"
#include "ResourceManager.h"


AActor::AActor(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;
}

AActor::~AActor()
{
}

void AActor::Tick()
{

}

void AActor::SetActorLocation(int x, int y)
{
	X = x;
	Y = y;
}

