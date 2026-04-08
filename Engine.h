#pragma once
#include <Windows.h>
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")
#pragma comment(lib, "SDL2_mixer")
#pragma comment(lib, "SDL2_ttf")


class UWorld;
class UResourceManager;

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
	void Render(int InX, int InY,int R, int G, int B);
	void Filp(); //1,2번 버퍼를 돌려주는 함수.
	void TermBuffer();

	void Stop();

	inline const SDL_Event& GetEvent()
	{
		return MyEvent;
	}

	const float GetDeltaSeconds()
	{
		return DeltaSeconds;
	}

	inline SDL_Renderer* GetRenderer() const
	{
		return MyRender;
	}

	inline SDL_Window* GetWindow() const
	{
		return MyWindow;
	}

	inline UResourceManager* GetResourceManager() const
	{
		return ResourceManager;
	}

	void Render(int InX, int InY, SDL_Texture* InTexture);

	TTF_Font* Font;
private:
	void Input();
	void Tick();
	void Render();



	UWorld* World;
	SDL_Window* MyWindow;
	SDL_Renderer* MyRender;
	SDL_Event MyEvent; //포인터 변수가 아니면 전방선언이 안되서 라이브러리를 포함해줘야한다.

	int bIsRunning : 1;

	float DeltaSeconds;

	UResourceManager* ResourceManager;

};

#define GEngine     UEngine::GetInstance()