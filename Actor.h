#pragma once
class AActor
{
public:
	AActor(int InX = 0, int InY = 0, char InMesh = ' ');
	virtual ~AActor();

	virtual void Tick();
	virtual void Render();

	void SetActorLocation(int x, int y);

protected:
	int X;
	int Y;
	char Mesh;

};

