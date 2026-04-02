#pragma once
#include <string>

enum Layer
{
	Floor = 0,
	Wall = 1,
	Goal = 2,
	Monster = 3,
	Player = 4
};

struct SDL_Texture;
struct SDL_Surface;


class AActor
{
public:
	AActor(int InX = 0, int InY = 0, char InMesh = ' ', int InZOrder = Layer::Floor);
	virtual ~AActor();

	virtual void BeginPlay();
	virtual void Tick();
	virtual void Render();

	void SetActorLocation(int x, int y);

	const int GetWeight()
	{
		return ZOrder;
	}

	virtual void Load(std::string Filename);

protected:
	int X;
	int Y;

	int R;
	int G;
	int B;

	char Mesh;
	int ZOrder; //렌더링 순서 가중치

	SDL_Texture* Texture;
	SDL_Surface* Image;

	int SpriteX = 0;
	int SpriteY = 0;

};

