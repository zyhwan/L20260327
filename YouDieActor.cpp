#include "YouDieActor.h"
#include "TextRenderComponent.h"

AYouDieActor::AYouDieActor()
{
	TextRenderComponent->SetText("You Died.");
	X = 270;
	Y = 300;

	TextRenderComponent->ZOrder = 200;
	TextRenderComponent->bIsVisible = false;
}

AYouDieActor::~AYouDieActor()
{
}
