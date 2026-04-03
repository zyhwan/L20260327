#include <iostream>
#include <fstream>
#include "World.h"
#include "Actor.h"
#include "Player.h"
#include "Monster.h"
#include "Floor.h"
#include "Wall.h"
#include "Goal.h"
#include "Engine.h"
#include <algorithm>
#include "SpriteComponent.h"

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
	for (auto Actor : Actors)
	{
		delete Actor;
	}
	Actors.clear();
}

void UWorld::Load(std::string MapName)
{
	std::ifstream File(MapName);

	if (!File.is_open())
	{
		std::cout << "파일을 열지 못함." << std::endl;
		return;
	}

	int Y = 0;

	int MaxX = -1;
	int MaxY = -1;

	std::string Line;

	while (!File.eof())
	{
		std::getline(File, Line);
		for (int i = 0; i < Line.length(); ++i)
		{
			if (Line[i] == ' ')
			{
				SpawnActor<AFloor>()->SetActorLocation(i, Y);
			}
			if (Line[i] == '#')
			{
				SpawnActor<AWall>()->SetActorLocation(i, Y);
				SpawnActor<AFloor>()->SetActorLocation(i, Y);
			}
			if (Line[i] == 'M')
			{
				SpawnActor<AMonster>()->SetActorLocation(i, Y);
				SpawnActor<AMonster>()->SetActorLocation(i, Y);
				SpawnActor<AFloor>()->SetActorLocation(i, Y);
			}
			if (Line[i] == 'G')
			{
				SpawnActor<AGoal>()->SetActorLocation(i, Y);
				SpawnActor<AFloor>()->SetActorLocation(i, Y);
			}
			if (Line[i] == 'P')
			{
				SpawnActor<APlayer>()->SetActorLocation(i, Y);
				SpawnActor<AFloor>()->SetActorLocation(i, Y);
			}
			if (MaxX < i)
			{
				MaxX = i;
			}
		}
		++Y;
	}

	MaxX += 1;
	MaxY = Y;

	SDL_SetWindowSize(GEngine->GetWindow(), MaxX * 80, MaxY * 80);

	std::sort(Actors.begin(), Actors.end(), [&](AActor* a, AActor* b) -> int {
		USpriteComponent* FirstRenderComponet = nullptr;
		for (auto Component : a->Components)
		{
			FirstRenderComponet = dynamic_cast<USpriteComponent*>(Component);
			if (FirstRenderComponet)
			{
				break;
			}
		}
		if (!FirstRenderComponet)
		{
			return 0;
		}

		USpriteComponent* SecondRenderComponet = nullptr;
		for (auto Component : b->Components)
		{
			SecondRenderComponet = dynamic_cast<USpriteComponent*>(Component);
			if (SecondRenderComponet)
			{
				break;
			}
		}
		if (!SecondRenderComponet)
		{
			return 0;
		}

		return (FirstRenderComponet->ZOrder < SecondRenderComponet->ZOrder ? 1 : 0);

		});

}

void UWorld::Tick()
{
	for (auto actors : Actors)
	{
		actors->Tick();
	}
}

void UWorld::Render()
{
	//그리기 전에 지워주기
	GEngine->Clear();

	for (auto actors : Actors)
	{
		//모든 엑터 중에서 Render 가능한 컴포넌트가 있으면 렌더 하기.

		for (auto Component : actors->Components)
		{
			//추상 클래스는 dynamic_cast가 안된다. 인스턴스를 못뽑기 때문에 변환이 안된다.
			IRenderableComponent* RenderComponet = dynamic_cast<IRenderableComponent*>(Component);
			if (RenderComponet)
			{
				RenderComponet->Render();
			}

		}
	}

	//그리고 나서 다음 버퍼로 바꿔주기
	GEngine->Filp();
}