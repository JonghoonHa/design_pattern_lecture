#include <iostream>
using namespace std;

// �����ڿ����� �����Լ��� �������� �ʽ��ϴ�.!!
// �Ļ�Ŭ������ �������ص� �׻� �ڽ��� ����� ȣ��˴ϴ�.

class Base
{
public:
	Base() { goo();  } // 1 ȣ����
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
	d.foo();  // 2 ȣ��
}