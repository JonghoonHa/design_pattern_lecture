// 1_생성자.cpp
#include <iostream>
using namespace std;

// 1. 기반 클래스의 생성자는 기본적으로 default 생성자가 호출된다.

// 2. 상속 관계에서 생성자/소멸자 호출의 정확한 원리
//    컴파일러가 파생 클래스의 생성자의 초기화 리스트에
//    기반 클래스 생성자를 호출하는 코드를 만들어 주는 것

class Base
{
public:
	Base()      { cout << "Base()" << endl; }
	Base(int a) { cout << "Base(int)" << endl; }
	~Base()     { cout << "~Base()" << endl; }
};

class Derived : public Base
{
public:
	Derived()    /*: Base(a)*/{ cout << "Derived()" << endl; }  // 컴파일러가 주석 부분을 자동으로 생성한다.
	Derived(int a) : Base(a) { cout << "Derived(int)" << endl; } // ': Base(a)'로 기반 클래스에서 int 타입의 생성자를 부르게 만들었다.
	~Derived()               { cout << "~Derived()" << endl; }
};

int main()
{
	Derived d(5);
}