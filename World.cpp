#include <iostream>
#include <fstream>
#include "World.h"
#include "Actor.h"
#include "Player.h"
#include "Monster.h"
#include "Floor.h"
#include "Wall.h"
#include "Goal.h"
#include <algorithm>

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
			}
			if (Line[i] == 'M')
			{
				SpawnActor<AMonster>()->SetActorLocation(i, Y);
			}
			if (Line[i] == 'G')
			{
				SpawnActor<AGoal>()->SetActorLocation(i, Y);
			}
			if (Line[i] == 'P')
			{
				SpawnActor<APlayer>()->SetActorLocation(i, Y);
			}
		}
		++Y;
	}

	std::sort(Actors.begin(), Actors.end(), [](AActor* a, AActor* b) {
		return a->GetWeight() < b->GetWeight();
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
	for (auto actors : Actors)
	{
		actors->Render();
	}
}