#pragma once
#include "SpriteComponent.h"


class USpriteAnimationComponent : public USpriteComponent
{
public:
	USpriteAnimationComponent();
	virtual ~USpriteAnimationComponent();

	virtual void Render() override;
	virtual void Tick() override;
	int SpriteIndexX = 0;
	int SpriteIndexY = 0;

	float TotalTime = 0;
	float ExecutionTime = 0.1f;

	float W;
	float H;

protected:

};

