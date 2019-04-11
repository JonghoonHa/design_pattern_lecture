// �����Լ��� ����
#include <iostream>
using namespace std;

// ������ �� Animal�� ��� �����Լ��� �ּҸ� �˰��־�� �մϴ�.
// �����Ϸ��� �Ʒ� �迭�� �����մϴ�.

void* animal_table[] = { &Animal::foo, &Animal::goo };

class Animal
{
	void* vtptr; // �����Ϸ��� ����
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
	p->foo(); // foo�� �����Լ��ϱ� p�� ����Ű�� �޸� ���� �� ȣ��
}