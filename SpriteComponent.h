#pragma once
#include "Component.h"
#include "RenderableComponent.h"

class USpriteComponent : public UComponent, IRenderableComponent
{
public:
	USpriteComponent();
	~USpriteComponent();


	//UComponent의 구현, abstract class
	virtual void BeginPlay() override;
	virtual void Tick() override;

	//IRenderableComponent를 구현, 인터페이스라는 구현.
	virtual void Render() override;

};

