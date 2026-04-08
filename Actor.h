#pragma once
#include <string>
#include <vector>
#include "SpriteComponent.h"
#include <functional>

using FActorBeginOverlapSignature = std::function<void(class AActor*)>;

struct SDL_Surface;
struct SDL_Texture;

class UComponent;

class AActor
{
public:
	AActor(int InX = 0, int InY = 0);
	virtual ~AActor();

	virtual void Tick();
	virtual void BeginPlay();

	void SetActorLocation(int x, int y);

	std::vector<UComponent*> Components;

	inline int GetX() const
	{
		return X;
	}
	inline int GetY() const
	{
		return Y;
	}

	FActorBeginOverlapSignature OnActorBeginOverlap;

	virtual void ReceiveHit(class AActor* Other);
	class UWorld* GetWorld();

	void SetWorld(class UWorld* InWorld)
	{
		World = InWorld;
	}

	inline const std::string& GetName() const
	{
		return Name;
	}


protected:
	int X;
	int Y;

	template<typename T>
	T* CreateDefaultSubObject(std::string ComponentName)
	{
		T* temp = new T;
		temp->Owner = this;
		Components.push_back(temp);
		return temp;
	}

	class UWorld* World;

	std::string Name;
};

