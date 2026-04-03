#pragma once
#include "Actor.h"

class UCollisionComponent;

class ACharacter : public AActor
{
public:
	ACharacter();
	virtual ~ACharacter();

protected:
	bool PrdictMove(int InX, int InY); //추후에 무브먼트 컴포넌트로 만들어야한다.

};

