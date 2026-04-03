#include "Player.h"
#include "Engine.h"
#include "World.h"
#include "GameplayStatics.h"
#include "ResourceManager.h"
#include "SpriteComponent.h"
#include "SpriteAnimationComponent.h"
#include "CollisionComponent.h"

APlayer::APlayer(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;

	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Data/player.bmp", true, 255, 0, 255);
	SpriteAnimationComponent = CreateDefaultSubObject<USpriteAnimationComponent>("Sprite");
	SpriteAnimationComponent->ZOrder = 100;
	SpriteAnimationComponent->Image = TempResource.Image;
	SpriteAnimationComponent->Texture = TempResource.Texture;
	SpriteAnimationComponent->W = (float)(SpriteAnimationComponent->Image->w / 5);
	SpriteAnimationComponent->H = (float)(SpriteAnimationComponent->Image->h / 5);
	SpriteAnimationComponent->ExecutionTime = 0.1f;

	CollisionComponent = CreateDefaultSubObject<UCollisionComponent>("Collision");
	CollisionComponent->bIsGenerateHit = true;
	CollisionComponent->bIsGenerateOverlap = true;
}

APlayer::~APlayer()
{


}

void APlayer::BeginPlay()
{
	__super::BeginPlay();
	OnActorBeginOverlap = [&](AActor* Other) -> void {
		//충돌 로직.
		};
	//OnActorBeginOverlap = ProcessBeginOverlap;
}

void APlayer::Tick()
{
	__super::Tick();
	Move();
	Attack();
}

void APlayer::ReceiveHit(AActor* Other)
{

}

void APlayer::ProcessBeginOverlap(AActor* OtherActor)
{

}

void APlayer::Move()
{
	SDL_Event Event = GEngine->GetEvent();

	if (Event.type == SDL_KEYDOWN)
	{
		if (Event.key.keysym.sym == SDLK_w && PrdictMove(X, Y - 1))
		{
			--Y;
			SpriteAnimationComponent->SpriteIndexY = 2;
		}
		if (Event.key.keysym.sym == SDLK_s && PrdictMove(X, Y + 1))
		{
			++Y;
			SpriteAnimationComponent->SpriteIndexY = 3;
		}
		if (Event.key.keysym.sym == SDLK_a && PrdictMove(X - 1, Y))
		{
			--X;
			SpriteAnimationComponent->SpriteIndexY = 0;
		}
		if (Event.key.keysym.sym == SDLK_d && PrdictMove(X + 1, Y))
		{
			++X;
			SpriteAnimationComponent->SpriteIndexY = 1;
		}
		if (Event.key.keysym.sym == SDLK_ESCAPE)
		{
			GEngine->Stop();
		}
	}

}

void APlayer::Attack()
{
	SDL_Event Event = GEngine->GetEvent();
	if (Event.key.keysym.sym == SDLK_f)
	{
		SpriteAnimationComponent->SpriteIndexY = 4;
		SpriteAnimationComponent->TotalTime = 0.f;
	}

}
