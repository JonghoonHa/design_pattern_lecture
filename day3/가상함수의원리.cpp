// 가상함수의 원리
#include <iostream>
using namespace std;

class Animal
{
public:
	virtual void Cry() { cout << "Animal Cry" << endl; } // 1
};
class Dog : public Animal
{
public:
	virtual void Cry() { cout << "Dog Cry" << endl; } // 2
};
int main()
{
	Animal a; a.Cry(); // 1
	Dog d; d.Cry(); // 2

	Animal* p = &d;
	/*
	int n;
	cin >> n;
	if (n == 1) p = &a;
	*/

	// 컴파일 시간에 p가 누구를 가리킬지 알 수 있을까? 몰러~
	p->Cry();
}
// p->Cry() 를 어디로 연결할 것인가? 함수 바인딩

// 1. static binding : 컴파일러가 컴파일 시간에 결정
//                     무조건 포인터 타입으로만 결정
//                     -> p가 Animal* 라면 Animal Cry 호출
// == early binding

// 2. dynamic binding : 컴파일 시 p 가 가리키는 메모리를 조사하는 코드 생성.
//                      실행 시 메모리 조사 후 호출
//                      p가 Animal* 라도 Dog를 가리키면 Dog Cry 호출
// == late binding     느리다.
//                     java, objective-c, swift 등 대부분의 oop 언어. C++와 C#의 가상함수