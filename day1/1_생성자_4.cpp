#include <iostream>
using namespace std;

// ������ ȣ�� ���� - ����ڰ� ������ ������ �� ����
// 1. ��� Ŭ������ ����� ������
// 2. ��� Ŭ������ ������
// 3. �ڽ��� ����� ������
// 4. �ڽ��� ������

struct BM { BM() { cout << "BM()" << endl; } };
struct DM { DM() { cout << "DM()" << endl; } };

struct Base
{
	BM bm;
	Base() { cout << "BM()" << endl; }
};

struct Derived : public Base
{
	DM dm;
	Derived() { cout << "DM()" << endl; }
};

int main()
{
	Derived d;
}