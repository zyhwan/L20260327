#pragma once
#include <Windows.h>

class UWorld;

class UEngine
{
private:
	UEngine();

	static UEngine* Instance;
public:
	static UEngine* GetInstance();

	~UEngine();

	void Init();
	void Term();
	void Run();
	UWorld* GetWorld();


	//Renderer
	HANDLE ScreenBufferHandle[2]; //그려야할 버퍼(도화지라 생각하면 됨)
	int ActiveScreenBufferIndex = 0;//현재 그리는 버퍼의 인덱스.

	void InitBuffer();
	void Clear(); //이전 그림 지우기.
	void Render(int InX, int InY, char InMesh);
	void Filp(); //1,2번 버퍼를 돌려주는 함수.
	void TermBuffer();

	static int KeyCode;
private:
	void Input();
	void Tick();
	void Render();

	UWorld* World;

	int bIsRunning : 1;
};

#define GEngine     UEngine::GetInstance()