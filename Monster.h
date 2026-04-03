#pragma once
#include "Actor.h"

class USpriteComponent;
class UCollisionComponent;

class AMonster : public AActor
{
public:
	AMonster(int InX = 0, int InY = 0, char InMesh = 'M');
	virtual ~AMonster();


	virtual void Tick() override;

	UCollisionComponent* CollisionComponent;

private:
	bool PrdictMove(int InX, int InY); //추후에 무브먼트 컴포넌트로 만들어야한다.

	USpriteComponent* SpriteComponent;

	float TotalTime = 0.0f;
	float ExecutionTime = 0.5f;
};

