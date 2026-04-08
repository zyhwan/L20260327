#include "TextRenderComponent.h"
#include "SDL_ttf.h"
#include "Engine.h"
#include "Actor.h"

UTextRenderComponent::UTextRenderComponent()
{

}

UTextRenderComponent::~UTextRenderComponent()
{
	if (Surface)
	{
		SDL_FreeSurface(Surface);
	}
	if (Texture)
	{
		SDL_DestroyTexture(Texture);
	}
}

void UTextRenderComponent::BeginPlay()
{
}

void UTextRenderComponent::Tick()
{
}

void UTextRenderComponent::Render()
{
	SDL_Rect DestinationRect{ Owner->GetX(), Owner->GetY(), Surface->w, Surface->h };

	SDL_RenderCopy(GEngine->GetRenderer(), Texture, nullptr, &DestinationRect);
}

void UTextRenderComponent::SetText(std::string InText)
{
	Text = InText;
	//TTF에서 메모리에 BMP로 올리고 우리는 이를 surface라고 부른다.
	Surface = TTF_RenderText_Solid(GEngine->Font, Text.c_str(), SDL_Color{ 255, 0, 0, 0 });
	Texture = SDL_CreateTextureFromSurface(GEngine->GetRenderer(), Surface);
}
