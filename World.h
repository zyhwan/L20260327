#pragma once
#include <vector>
#include <string>

class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	template<typename T>
	AActor* GetActorOfClass()
	{
		for (auto Actor : Actors)
		{
			T* Target = dynamic_cast<T*>(Actor);
			if (Target)
			{
				return Target;
			}
		}
		return nullptr;
	}

	void Load(std::string MapName);
	void Tick();
	void Render();

	inline std::vector<AActor*> GetActors()
	{
		return Actors;
	}

	template<typename T>
	AActor* SpawnActor()
	{
		AActor* NewActor = new T;
		Actors.push_back(NewActor);

		return NewActor;
	}

private:
	std::vector<AActor*> Actors;
};

