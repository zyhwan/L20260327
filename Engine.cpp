#include <conio.h>
#include <iostream>
#include "Engine.h"
#include "World.h"
#include "Actor.h"
#include "SDL.h"
#include "ResourceManager.h"
#include "AudioComponent.h"

UEngine* UEngine::Instance = nullptr;

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
	//초기화
	SDL_Init(SDL_INIT_EVERYTHING);

	//윈도우는 메모리에 잡히기때문에 포인터로 연결해줌.
	MyWindow = SDL_CreateWindow("Hello", 100, 100, 1024, 768, SDL_WINDOW_SHOWN);
	//렌더러 만들기 윈도우와 동일하다.
	MyRender = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

	TTF_Init();
	
	Font = TTF_OpenFont("./Data/Font.ttf", 100);

	DeltaSeconds = 0;

    bIsRunning = 1;
	
	ResourceManager = new UResourceManager();
	
	InitBuffer();
    World = new UWorld();
}

void UEngine::Term()
{
	//추후에 리소스 매니저로 옮기기.
	if(Font)
	{
		TTF_CloseFont(Font);
	}

	SDL_DestroyRenderer(MyRender);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();

    delete World;
	delete ResourceManager;
	TermBuffer();
    World = nullptr;
	ResourceManager = nullptr;
}

void UEngine::Run()
{
	Uint64 CurrentTime;
	Uint64 ElapsedTime;
	while (bIsRunning)
	{
		ElapsedTime = SDL_GetTicks64();
		SDL_PollEvent(&MyEvent);

		Input();
		Tick();
		Render();

		CurrentTime = SDL_GetTicks64();
		DeltaSeconds = (float)(CurrentTime - ElapsedTime) / 1000.0f;

	}
}

UWorld* UEngine::GetWorld()
{
    return World;
}

void UEngine::Input()
{
	//if (_kbhit())
	//{
	//	KeyCode = _getch();
	//}
}

void UEngine::Tick()
{
	if (GetEvent().type == SDL_QUIT)
	{
		bIsRunning = false;
	}
    World->Tick();
}

void UEngine::Render()
{

    World->Render();

	SDL_RenderPresent(MyRender);
}


void UEngine::InitBuffer()
{
	//ScreenBufferHandle[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL,
	//	CONSOLE_TEXTMODE_BUFFER, NULL);
	//ScreenBufferHandle[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL,
	//	CONSOLE_TEXTMODE_BUFFER, NULL);

	////커서 없애기
	//CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	//ConsoleCursorInfo.dwSize = 1;
	//ConsoleCursorInfo.bVisible = FALSE;

	//SetConsoleCursorInfo(ScreenBufferHandle[0], &ConsoleCursorInfo);
	//SetConsoleCursorInfo(ScreenBufferHandle[1], &ConsoleCursorInfo);
}

void UEngine::Clear()
{
	SDL_SetRenderDrawColor(MyRender, 255, 255, 255, 255);
	SDL_RenderClear(MyRender);
	////모든 버퍼 지우기
	//DWORD DW;
	////가로 80 세로 25만큼 지워달라고 요청.
	//FillConsoleOutputCharacter(ScreenBufferHandle[ActiveScreenBufferIndex], ' ', 100 * 100, COORD{ 0, 0 }, &DW);
}

void UEngine::Render(int InX, int InY, char InMesh)
{
	//char Mesh[2] = { 0, };
	//Mesh[0] = InMesh;

	////선택한 버퍼를 어느 좌표부터 그려주는지 써줌.
	//SetConsoleCursorPosition(ScreenBufferHandle[ActiveScreenBufferIndex], COORD{ (SHORT)InX, (SHORT)InY });
	//WriteFile(ScreenBufferHandle[ActiveScreenBufferIndex], Mesh, 1, NULL, NULL);


}

void UEngine::Render(int InX, int InY, int R, int G, int B)
{
	int TileSize = 80;
	SDL_SetRenderDrawColor(MyRender, R, G, B, 255);
	//SDL_RenderDrawPoint(MyRender, InX, InY);

	SDL_Rect Rect{ InX * TileSize, InY * TileSize, TileSize, TileSize };

	SDL_RenderFillRect(MyRender, &Rect);
}

void UEngine::Render(int InX, int InY, SDL_Texture* InTexture)
{
	int TileSize = 80;

	SDL_Rect Rect{ InX * TileSize, InY * TileSize, TileSize, TileSize };
	SDL_RenderCopy(MyRender, InTexture, nullptr, &Rect);
}

void UEngine::Filp()
{
	//SetConsoleActiveScreenBuffer(ScreenBufferHandle[ActiveScreenBufferIndex]);
	//ActiveScreenBufferIndex = !ActiveScreenBufferIndex;
}

void UEngine::TermBuffer()
{
	//CloseHandle(ScreenBufferHandle[0]);
	//CloseHandle(ScreenBufferHandle[1]);
}


void UEngine::Stop()
{
	bIsRunning = false;
}
