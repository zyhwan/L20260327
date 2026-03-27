#include <iostream>
#include <Windows.h>
#include "Actor.h"

AActor::AActor(int InX, int InY, char InMesh, int InWeight)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	Weight = InWeight;
}

AActor::~AActor()
{
}

void AActor::Tick()
{

}

void AActor::Render()
{
	COORD Coordinate;
	Coordinate.X = X;
	Coordinate.Y = Y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coordinate);

	std::cout << Mesh;
}

void AActor::SetActorLocation(int x, int y)
{
	X = x;
	Y = y;
}
