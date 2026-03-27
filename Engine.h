#pragma once

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

	static int KeyCode;
private:
	void Input();
	void Tick();
	void Render();

	UWorld* World;

	int bIsRunning : 1;
};

