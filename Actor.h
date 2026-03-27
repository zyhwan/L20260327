#pragma once

enum Layer
{
	Terrain = 0,
	Goal = 1,
	Monster = 2,
	Player = 3
};


class AActor
{
public:
	AActor(int InX = 0, int InY = 0, char InMesh = ' ', int InWeight = Layer::Terrain);
	virtual ~AActor();

	virtual void Tick();
	virtual void Render();

	void SetActorLocation(int x, int y);

	int GetWeight()
	{
		return Weight;
	}

protected:
	int X;
	int Y;
	char Mesh;
	int Weight; //렌더링 순서 가중치
};

