#pragma once
#include "Actor.h"

class USpriteComponent;

class APlayer : public AActor
{
public:
	APlayer(int InX = 0, int InY = 0, char InMesh = 'P');
	virtual ~APlayer();

	virtual void Tick() override;

	void Move();
	void Attack();

	USpriteComponent* SpriteComponent;
private:

	int SpriteIndexX;
	int SpriteIndexY;
	 
	float TotalTime;
	float ExecutionTime = 0.1f;
};

