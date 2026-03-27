#include <iostream>
#include "Engine.h"
#include "World.h"

using namespace std;

int main()
{
	
	UEngine* MyEngine = UEngine::GetInstance();
	MyEngine->GetWorld()->Load("MyMaps.txt");
	MyEngine->Run();
	MyEngine->Term();

	return 0;
}