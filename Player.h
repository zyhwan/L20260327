#pragma once
#include "Actor.h"

class USpriteAnimationComponent;
class UCollisionComponent;
class AActor;

class APlayer : public AActor
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
	bool PrdictMove(int InX, int InY); //추후에 무브먼트 컴포넌트로 만들어야한다.

};

