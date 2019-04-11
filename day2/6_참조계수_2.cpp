#include <iostream>
using namespace std;

class Car
{
	int color;
	int mCount = 0; // ��������� ���� ���

public:
	~Car() { cout << "~Car" << endl; }

	void AddRef() { ++mCount; }
	void Release() { if (--mCount == 0) delete this; }
};

int main()
{
	Car* p1 = new Car;
	p1->AddRef(); // ��Ģ 1. ��ü ���� �ÿ� ������� ����
	Car* p2 = p1;
	p2->AddRef(); // ��Ģ 2. ��ü ������ ���� �� ������� ����

	p2->Release(); // ��Ģ 3. ������ ��� �� ������� ����
	p1->Release();
}