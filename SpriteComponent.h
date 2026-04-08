#pragma once
#include "Component.h"
#include "RenderableComponent.h"
#include "SDL.h"

class USpriteComponent : public UComponent, public IRenderableComponent
{
public:
	USpriteComponent();
	virtual ~USpriteComponent();


	//UComponent의 구현, abstract class
	virtual void BeginPlay() override;
	virtual void Tick() override;

	//IRenderableComponent를 구현, 인터페이스라는 구현.
	virtual void Render() override;

	SDL_Texture* Texture = nullptr;
	SDL_Surface* Image = nullptr;
};

