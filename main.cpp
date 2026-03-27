#include <iostream>
#include "Engine.h"
#include "World.h"

#include "Actor.h"
#include "Player.h"

using namespace std;

int main()
{

	UEngine* MyEngine = UEngine::GetInstance();
	MyEngine->GetWorld()->Load("MyMaps.txt");
	MyEngine->Run();

	return 0;
}