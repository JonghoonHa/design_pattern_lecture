// �����Լ��� ����
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
	p->foo(); // foo�� �����Լ��ϱ� p�� ����Ű�� �޸� ���� �� ȣ��
}