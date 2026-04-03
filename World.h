#pragma once
#include <vector>
#include <string>
class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	void Load(std::string MapName);
	void Tick();
	void Render();

	inline const std::vector<AActor*> GetActors()
	{
		return Actors;
	}

	template<typename T>
	AActor* SpawnActor()
	{
		AActor* NewActor = new T();
		Actors.push_back(NewActor);
		return NewActor;
	}
private:
	std::vector<AActor*> Actors;
};

