#pragma once
#include "Actor.h"

class AMonster : public AActor
{
public:
	AMonster(int InX = 0, int InY = 0, char InMesh = 'M', int InWeight = Layer::Monster);
	virtual ~AMonster();


	virtual void Tick() override;

private:
	float TotalTime = 0.0f;
	float ExecutionTime = 0.5f;
};

