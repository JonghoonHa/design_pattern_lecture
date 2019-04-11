#include <iostream>
using namespace std;

// 생성자에서는 가상함수가 동작하지 않습니다.!!
// 파생클래스가 재정의해도 항상 자신의 멤버가 호출됩니다.

class Base
{
public:
	Base() { goo();  } // 1 호출함
	void foo() { goo(); }
	virtual void goo() { cout << "Base goo" << endl; } // 1
};

class Derived : public Base
{
public:
	virtual void goo() { cout << "Derived goo" << endl; } // 2
};

int main()
{
	Derived d;
	d.foo();  // 2 호출
}