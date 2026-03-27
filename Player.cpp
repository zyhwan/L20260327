#include "Player.h"
#include "Engine.h"

APlayer::APlayer(int InX, int InY, char InMesh, int InWeight)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	Weight = InWeight;
}

APlayer::~APlayer()
{


}

void APlayer::Tick()
{
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
