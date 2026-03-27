#include <iostream>
#include "Engine.h"
#include "World.h"
#include "Actor.h"
#include "Player.h"

using namespace std;


//template<typename T>
//void SelectSort(T* InData, const int& InOutsize, int (*Compare)(int A, int B))
//{
//	int temp = 0;
//
//	for (int i = 0; i < InOutsize; ++i)
//	{
//		for (int j = 0; j < InOutsize; ++j)
//		{
//			if (Compare(InData[i], InData[j]) == 1)
//			{
//				temp = InData[i];
//				InData[i] = InData[j];
//				InData[j] = temp;
//			}
//		}
//	}
//}
//
//
//
//int Ascending(int A, int B)
//{
//	if (A > B)
//	{
//		return 1;
//	}
//	else if (A == B)
//	{
//		return 0;
//	}
//	return -1;
//}
//
//int Decending(int A, int B)
//{
//	if (A < B)
//	{
//		return -1;
//	}
//	else if (A == B)
//	{
//		return 0;
//	}
//	return 1;
//}
//
//void test(int x, int y)
//{
//
//}
//
//void (*FunctionPointer)(int, int);


int main()
{
	//FunctionPointer = test;

	//int Data[10] = { 9, 3, 1, 5, 4, 6, 7, 8, 2, 10 };

	//int temp = 0;

	////일급함수, 함수도 변수에 저장 가능함.
	//int (*Compare)(int, int) = [](int, int) -> int { return 0; };

	//SelectSort(Data, 10, [](int A, int B) -> int {
	//	if (A < B)
	//	{
	//		return 1;
	//	}
	//	else if (A == B)
	//	{
	//		return 0;
	//	}

	//	return -1;
	//	}
	//);

	//for (auto v : Data)
	//{
	//	cout << v;
	//}

	GEngine->GetWorld()->Load("MyMaps.txt");
	GEngine->Run();

	delete GEngine;

	return 0;
}