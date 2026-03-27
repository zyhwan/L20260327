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
    bIsRunning = 1;
	InitBuffer();
    World = new UWorld();
}

void UEngine::Term()
{
    delete World;
	TermBuffer();
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


void UEngine::InitBuffer()
{
	ScreenBufferHandle[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL,
		CONSOLE_TEXTMODE_BUFFER, NULL);
	ScreenBufferHandle[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL,
		CONSOLE_TEXTMODE_BUFFER, NULL);

	//커서 없애기
	CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	ConsoleCursorInfo.dwSize = 1;
	ConsoleCursorInfo.bVisible = FALSE;

	SetConsoleCursorInfo(ScreenBufferHandle[0], &ConsoleCursorInfo);
	SetConsoleCursorInfo(ScreenBufferHandle[1], &ConsoleCursorInfo);
}

void UEngine::Clear()
{
	//모든 버퍼 지우기
	DWORD DW;
	//가로 80 세로 25만큼 지워달라고 요청.
	FillConsoleOutputCharacter(ScreenBufferHandle[ActiveScreenBufferIndex], ' ', 100 * 100, COORD{ 0, 0 }, &DW);
}

void UEngine::Render(int InX, int InY, char InMesh)
{
	char Mesh[2] = { 0, };
	Mesh[0] = InMesh;

	//선택한 버퍼를 어느 좌표부터 그려주는지 써줌.
	SetConsoleCursorPosition(ScreenBufferHandle[ActiveScreenBufferIndex], COORD{ (SHORT)InX, (SHORT)InY });
	WriteFile(ScreenBufferHandle[ActiveScreenBufferIndex], Mesh, 1, NULL, NULL);
}

void UEngine::Filp()
{
	SetConsoleActiveScreenBuffer(ScreenBufferHandle[ActiveScreenBufferIndex]);
	ActiveScreenBufferIndex = !ActiveScreenBufferIndex;
}

void UEngine::TermBuffer()
{
	CloseHandle(ScreenBufferHandle[0]);
	CloseHandle(ScreenBufferHandle[1]);
}
