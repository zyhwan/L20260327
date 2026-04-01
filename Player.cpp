#include "Player.h"
#include "Engine.h"

APlayer::APlayer(int InX, int InY, char InMesh, int InWeight)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = InWeight;

	R = 255;
	G = 0;
	B = 0;
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
		}
		if (Event.key.keysym.sym == SDLK_s)
		{
			++Y;
			SetActorLocation(X, Y);
		}
		if (Event.key.keysym.sym == SDLK_a)
		{
			--X;
			SetActorLocation(X, Y);
		}
		if (Event.key.keysym.sym == SDLK_d)
		{
			++X;
			SetActorLocation(X, Y);
		}
		if (Event.key.keysym.sym == SDLK_ESCAPE)
		{
			GEngine->Stop();
		}
	}
}
