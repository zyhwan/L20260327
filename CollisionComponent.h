#pragma once
#include "Component.h"


class UCollisionComponent : public UComponent
{
public:
	UCollisionComponent();
	virtual ~UCollisionComponent();

	virtual void BeginPlay() override;
	virtual void Tick() override;

	int bIsGenerateOverlap : 1; //겹쳤을 때 물리량은 주고받지 않고 이벤트만 수행하는 충돌.
	int bIsGenerateHit : 1; //실제 물리적인 충돌을 하는 충돌.

};

