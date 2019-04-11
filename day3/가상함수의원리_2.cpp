// 가상함수의 원리
#include <iostream>
using namespace std;

class Animal
{
	int age;
public:
	virtual void foo() { cout << "A foo " << endl; }
	virtual void goo() { cout << "A goo " << endl; }
};

class Dog : public Animal
{
	int color;
public:
	virtual void foo() { cout << "D foo " << endl; }
};

int main()
{
	Animal a;
	Dog    d;
	Animal* p = &d;
	p->foo(); // foo는 가상함수니까 p가 가리키는 메모리 조사 후 호출
}