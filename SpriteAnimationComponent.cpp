#include "SpriteAnimationComponent.h"
#include "Engine.h"
#include "Actor.h"

USpriteAnimationComponent::USpriteAnimationComponent()
{
}

USpriteAnimationComponent::~USpriteAnimationComponent()
{
}

void USpriteAnimationComponent::Render()
{
	int TileSize = 80;

	SDL_Rect Rect = { SpriteIndexX * (int)W, SpriteIndexY * (int)H, (int)W, (int)H };
	SDL_Rect DestinationRect = { Owner->GetX() * TileSize, Owner->GetY() * TileSize, TileSize, TileSize };

	SDL_RenderCopy(GEngine->GetRenderer(), Texture, &Rect, &DestinationRect);
}

void USpriteAnimationComponent::Tick()
{
	TotalTime += GEngine->GetDeltaSeconds();

	if (TotalTime >= ExecutionTime)
	{
		SpriteIndexX += 1;
		SpriteIndexX = SpriteIndexX % 5;

		TotalTime = 0.0f;
	}
}
