#pragma once
#include "Actor.h"

class APlayer : public AActor
{
public:
	APlayer(int InX = 0, int InY = 0, char InMesh = 'P', int InWeight = Layer::Player);
	virtual ~APlayer();

	virtual void BeginPlay()override;
	virtual void Tick() override;
	void Move();

};

