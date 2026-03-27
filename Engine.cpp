#include "Engine.h"
#include <conio.h>
#include "World.h"
#include "Actor.h"

UEngine* UEngine::Instance = nullptr;
int UEngine::KeyCode = 0;

UEngine::UEngine()
{
    Init();
}

UEngine* UEngine::GetInstance()
{
    if (Instance == nullptr)
    {
        Instance = new UEngine();
    }
    return Instance;
}

UEngine::~UEngine()
{
    Term();
}

void UEngine::Init() 
{
    World = new UWorld();
    bIsRunning = 1;
}

void UEngine::Term()
{
    delete World;
    World = nullptr;
}

void UEngine::Run()
{
	while (bIsRunning)
	{
		Input();
		Tick();
		Render();
	}
}

UWorld* UEngine::GetWorld()
{
    return World;
}

void UEngine::Input()
{
    KeyCode = _getch();
}

void UEngine::Tick()
{
    World->Tick();
}

void UEngine::Render()
{
    World->Render();
}