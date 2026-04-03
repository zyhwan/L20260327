#include "Player.h"
#include "Engine.h"
#include "GameplayStatics.h"
#include "ResourceManager.h"
#include "SpriteComponent.h"

APlayer::APlayer(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;

	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/player.bmp", true, 255, 0, 255);
	SpriteComponent = CreateDefaultSubObject<USpriteComponent>("Sprite");
	SpriteComponent->ZOrder = 100;
	SpriteComponent->Image = TempResource.Image;
	SpriteComponent->Texture = TempResource.Texture;

	//Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/player.bmp", true, 255, 0, 255);
	//Image = TempResource.Image;
	//Texture = TempResource.Texture;

	//ImageW = Image->w / 5;
	//ImageH = Image->h / 5;

	//SpriteIndexX = 0; // 스프라이트 하나 값.
	//SpriteIndexY = 0; //
	//TotalTime = 0.f;
}

APlayer::~APlayer()
{


}

void APlayer::Tick()
{
	__super::Tick();
	Move();
	Attack();
}

void APlayer::Move()
{
	SDL_Event Event = GEngine->GetEvent();

	if (Event.type == SDL_KEYDOWN)
	{
		if (Event.key.keysym.sym == SDLK_w)
		{
			if (Y > 1)
			{
				--Y;
			}
			SetActorLocation(X, Y);
			SpriteIndexY = 2;
		}
		if (Event.key.keysym.sym == SDLK_s)
		{
			if (Y < 8)
			{
				++Y;
			}
			SetActorLocation(X, Y);
			SpriteIndexY = 3;
		}
		if (Event.key.keysym.sym == SDLK_a)
		{
			if (X > 1)
			{
				--X;
			}
			SetActorLocation(X, Y);
			SpriteIndexY = 0;
		}
		if (Event.key.keysym.sym == SDLK_d)
		{
			if (X < 8)
			{
				++X;
			}
			SetActorLocation(X, Y);
			SpriteIndexY = 1;
		}
		if (Event.key.keysym.sym == SDLK_ESCAPE)
		{
			GEngine->Stop();
		}
	}

	TotalTime += GEngine->GetDeltaSeconds();

	if (TotalTime >= ExecutionTime)
	{
		SpriteIndexX += 1;
		SpriteIndexX = SpriteIndexX % 5;

		TotalTime = 0.0f;
	}

}

void APlayer::Attack()
{
	SDL_Event Event = GEngine->GetEvent();
	if (Event.key.keysym.sym == SDLK_f)
	{
		SpriteIndexY = 4;
		TotalTime = 0.f;
	}

}
