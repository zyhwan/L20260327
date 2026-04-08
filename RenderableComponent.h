#pragma once
#include "Component.h"

//interface로 사용하는 클래스.
//순수가상함수를 포함한 추상 클래스

class IRenderableComponent
{
public:
	virtual void Render() = 0;
	
	int ZOrder = 0; //렌더링 순서 가중치

	int bIsVisible : 1; //visibility 여부 체크
};

