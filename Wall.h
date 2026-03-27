#pragma once
#include "Actor.h"

class AWall : public AActor
{
public:
	AWall(int InX = 0, int InY = 0, char InMesh = '#',int Weight = Layer::Wall);
	virtual ~AWall();


};

