#include "Character.h"
#include "Engine.h"
#include "World.h"
#include "CollisionComponent.h"

ACharacter::ACharacter()
{
}

ACharacter::~ACharacter()
{
}

bool ACharacter::PrdictMove(int InX, int InY)
{
	for (auto Other : GEngine->GetWorld()->GetActors())
	{
		//본인은 충돌체크 X
		if (Other == this)
		{
			continue;
		}

		for (auto Component : Other->Components)
		{
			UCollisionComponent* OtherCollision = dynamic_cast<UCollisionComponent*>(Component);
			if (OtherCollision)
			{
				if (OtherCollision->bIsGenerateHit && InX == Other->GetX() && InY == Other->GetY())
				{

					ReceiveHit(Other);
					return false;
				}
			}
		}
	}

	return true;
}