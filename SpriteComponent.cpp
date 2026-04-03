#include "SpriteComponent.h"
#include "Engine.h"
#include "Actor.h"

USpriteComponent::USpriteComponent()
{
}

USpriteComponent::~USpriteComponent()
{
}

void USpriteComponent::BeginPlay()
{
}

void USpriteComponent::Tick()
{
}

void USpriteComponent::Render()
{
	int TileSize = 80;
	SDL_Rect DestinationRect = { Owner->GetX() * TileSize, Owner->GetY() * TileSize, TileSize, TileSize };
	SDL_RenderCopy(GEngine->GetRenderer(), Texture, nullptr, &DestinationRect);
}
