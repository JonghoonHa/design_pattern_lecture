// 가상함수의 원리
#include <iostream>
using namespace std;

// 실행할 때 Animal의 모든 가상함수의 주소를 알고있어야 합니다.
// 컴파일러가 아래 배열을 생성합니다.

void* animal_table[] = { &Animal::foo, &Animal::goo };

class Animal
{
	void* vtptr; // 컴파일러가 생성
	int age;
public:
	Animal() : vptr(animal_table) {}

	virtual void foo() { cout << "A foo " << endl; }
	virtual void goo() { cout << "A goo " << endl; }
};

void* dog_table[] = { &Animal::foo, &Animal::goo };

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