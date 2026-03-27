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

private:
	void Input();
	void Tick();
	void Render();

	UWorld* World;

	int bIsRunning;
	static int KeyCode;
};

