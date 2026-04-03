#pragma once
#include "Character.h"

class USpriteAnimationComponent;

class APlayer : public ACharacter
{
public:
	APlayer(int InX = 0, int InY = 0, char InMesh = 'P');
	virtual ~APlayer();

	virtual void BeginPlay() override;
	virtual void Tick() override;
	void Move();
	void Attack();

	virtual void ReceiveHit(AActor* Other) override;
	void ProcessBeginOverlap(AActor* OtherActor);

	USpriteAnimationComponent* SpriteAnimationComponent;
	UCollisionComponent* CollisionComponent;

private:

};

