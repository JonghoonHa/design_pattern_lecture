// 1_������.cpp
#include <iostream>
using namespace std;

// 1. ��� Ŭ������ �����ڴ� �⺻������ default �����ڰ� ȣ��ȴ�.

// 2. ��� ���迡�� ������/�Ҹ��� ȣ���� ��Ȯ�� ����
//    �����Ϸ��� �Ļ� Ŭ������ �������� �ʱ�ȭ ����Ʈ��
//    ��� Ŭ���� �����ڸ� ȣ���ϴ� �ڵ带 ����� �ִ� ��

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
	Derived()    /*: Base(a)*/{ cout << "Derived()" << endl; }  // �����Ϸ��� �ּ� �κ��� �ڵ����� �����Ѵ�.
	Derived(int a) : Base(a) { cout << "Derived(int)" << endl; } // ': Base(a)'�� ��� Ŭ�������� int Ÿ���� �����ڸ� �θ��� �������.
	~Derived()               { cout << "~Derived()" << endl; }
};

int main()
{
	Derived d(5);
}