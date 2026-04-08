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
	for (auto Other : GetWorld()->GetActors())
	{
		if (Other == this) //자기 비교 할필요가 없음
		{
			continue;
		}

		for (auto OtherComponent : Other->Components)
		{
			UCollisionComponent* OtherCollision = dynamic_cast<UCollisionComponent*>(OtherComponent);
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