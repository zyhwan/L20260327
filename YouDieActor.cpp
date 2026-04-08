#include "YouDieActor.h"
#include "TextRenderComponent.h"

AYouDieActor::AYouDieActor()
{
	TextRenderComponent->SetText("You Died.");
	X = 200;
	Y = 150;
}

AYouDieActor::~AYouDieActor()
{
}
