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
	SDL_FreeSurface(Image);
	SDL_DestroyTexture(Texture);
}

void AActor::BeginPlay()
{
}

void AActor::Tick()
{

}

void AActor::Render()
{
	//GEngine->Render(X, Y, Mesh);
	//GEngine->Render(X, Y, R, G, B);
	GEngine->Render(X, Y, Texture);
}

void AActor::SetActorLocation(int x, int y)
{
	X = x;
	Y = y;
}

void AActor::Load(std::string Filename)
{
	Image = SDL_LoadBMP(Filename.c_str()); //메모리 ram에 적재
	
	SDL_SetColorKey(Image, SDL_TRUE, SDL_MapRGB(Image->format, 255, 255, 255));

	Texture = SDL_CreateTextureFromSurface(GEngine->GetRenderer(), Image); //gpu에서 관리.

}
