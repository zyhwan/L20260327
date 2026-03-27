#include "Player.h"
#include "Engine.h"

APlayer::APlayer(int InX, int InY, char InMesh, int InWeight)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = InWeight;
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
	if (UEngine::KeyCode == 'w' || UEngine::KeyCode == 'W')
	{
		--Y;
		SetActorLocation(X, Y);
	}
	if (UEngine::KeyCode == 's' || UEngine::KeyCode == 'S')
	{
		++Y;
		SetActorLocation(X, Y);
	}
	if (UEngine::KeyCode == 'a' || UEngine::KeyCode == 'A')
	{
		--X;
		SetActorLocation(X, Y);
	}
	if (UEngine::KeyCode == 'd' || UEngine::KeyCode == 'D')
	{
		++X;
		SetActorLocation(X, Y);
	}
}
