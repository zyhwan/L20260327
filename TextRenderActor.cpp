#include "TextRenderActor.h"
#include "TextRenderComponent.h"


ATextRenderActor::ATextRenderActor()
{
	TextRenderComponent = CreateDefaultSubObject<UTextRenderComponent>("TextRender");
}

ATextRenderActor::~ATextRenderActor()
{

}
