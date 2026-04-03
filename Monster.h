#pragma once
#include "Character.h"

class USpriteComponent;

class AMonster : public ACharacter
{
public:
	AMonster(int InX = 0, int InY = 0, char InMesh = 'M');
	virtual ~AMonster();


	virtual void Tick() override;
	
	UCollisionComponent* CollisionComponent;

private:
	USpriteComponent* SpriteComponent;

	float TotalTime = 0.0f;
	float ExecutionTime = 0.5f;
};

