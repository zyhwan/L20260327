#pragma once

//이걸 상속 받는 사람들한테 밑에 함수를 무조건 만들라고 강요하고 싶어.
//순수 가상함수가 있는 클래스를 추상 클래스라고 한다.
//추상 클래스가 되면 생성을 하지 못한다.
//용도 : 무조건 상속받아서 자식에서 이 함수를 무조건 재정의 해야한다는 의미이다.

//인터페이스 interface
class UComponent
{
public:
	UComponent();
	virtual ~UComponent();

	virtual void BeginPlay() = 0; //순수 가상 함수.
	virtual void Tick(); //구현 안하도 된다. 

};

