#include "Player.h"
#include "Engine.h"
#include "GameplayStatics.h"
#include "ResourceManager.h"

APlayer::APlayer(int InX, int InY, char InMesh, int InWeight)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = InWeight;

	R = 255;
	G = 0;
	B = 0;

	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/player.bmp", true, 255, 0, 255);
	Image = TempResource.Image;
	Texture = TempResource.Texture;

	ImageW = Image->w / 5;
	ImageH = Image->h / 5;

	SpriteIndexX = 0; // 스프라이트 하나 값.
	SpriteIndexY = 0; //
	TotalTime = 0.f;
}

APlayer::~APlayer()
{


}

void APlayer::BeginPlay()
{
	__super::BeginPlay();
}

void APlayer::Tick()
{
	__super::Tick();
	Move();
	Attack();
}

void APlayer::Render()
{
	int TileSize = 80;

	SDL_Rect SourceRect = { SpriteIndexX * ImageW, SpriteIndexY * ImageH, ImageW, ImageH };
	SDL_Rect Rect{ X * TileSize, Y * TileSize, TileSize, TileSize };
	SDL_RenderCopy(GEngine->GetRenderer(), Texture, &SourceRect, &Rect);

}

void APlayer::Move()
{
	SDL_Event Event = GEngine->GetEvent();

	if (Event.type == SDL_KEYDOWN)
	{
		if (Event.key.keysym.sym == SDLK_w)
		{
			--Y;
			SetActorLocation(X, Y);
			SpriteIndexY = 2;
		}
		if (Event.key.keysym.sym == SDLK_s)
		{
			++Y;
			SetActorLocation(X, Y);
			SpriteIndexY = 3;
		}
		if (Event.key.keysym.sym == SDLK_a)
		{
			--X;
			SetActorLocation(X, Y);
			SpriteIndexY = 0;
		}
		if (Event.key.keysym.sym == SDLK_d)
		{
			++X;
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
