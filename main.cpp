#include <iostream>
#include "Engine.h"
#include "World.h"
#include "Component.h" 

using namespace std;

int SDL_main(int argc, char* argv[])
{

	GEngine->GetWorld()->Load("MyMaps.txt");

	GEngine->Run();

	delete GEngine;

	return 0;
}
