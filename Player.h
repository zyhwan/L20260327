#pragma once
#include "Actor.h"

class APlayer : public AActor
{
public:
	APlayer(int InX = 0, int InY = 0, char InMesh = 'P', int InWeight = Layer::Player);
	virtual ~APlayer();

	virtual void BeginPlay()override;
	virtual void Tick() override;
	virtual void Render() override;

	void Move();
	virtual void Load(std::string Filename) override;

	void Attack();

private:
	int SpriteIndexX;
	int SpriteIndexY;

	int ImageH;
	int ImageW;

	float TotalTime;
	float ExecutionTime = 0.1f;
};

