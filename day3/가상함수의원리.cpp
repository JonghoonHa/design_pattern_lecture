// �����Լ��� ����
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

	// ������ �ð��� p�� ������ ����ų�� �� �� ������? ����~
	p->Cry();
}
// p->Cry() �� ���� ������ ���ΰ�? �Լ� ���ε�

// 1. static binding : �����Ϸ��� ������ �ð��� ����
//                     ������ ������ Ÿ�����θ� ����
//                     -> p�� Animal* ��� Animal Cry ȣ��
// == early binding

// 2. dynamic binding : ������ �� p �� ����Ű�� �޸𸮸� �����ϴ� �ڵ� ����.
//                      ���� �� �޸� ���� �� ȣ��
//                      p�� Animal* �� Dog�� ����Ű�� Dog Cry ȣ��
// == late binding     ������.
//                     java, objective-c, swift �� ��κ��� oop ���. C++�� C#�� �����Լ�