#include <iostream>
#include "Actor.h"
#include "Engine.h"
#include "ResourceManager.h"


AActor::AActor(int InX, int InY)
{
	X = InX;
	Y = InY;
}

AActor::~AActor()
{
	for (auto& Component : Components)
	{
		delete Component;
	}
	Components.clear();
}

void AActor::Tick()
{
	for (auto Component : Components)
	{
		Component->Tick();
	}
}

void AActor::BeginPlay()
{

}

void AActor::SetActorLocation(int x, int y)
{
	X = x;
	Y = y;
}

void AActor::ReceiveHit(AActor* Other)
{
}

