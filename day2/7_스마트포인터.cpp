// 7_����Ʈ������
#include <iostream>
using namespace std;

class Car
{
public:
	~Car() { cout << "~Car" << endl; }
	void Go() { cout << "Car Go" << endl; }

};

// ����Ʈ ������
// ����: ������ ��ü�� �ٸ� Ÿ���� ������ ������ �ϴ� ��
// ����: -> �� * �����ڸ� �������ؼ� ������ó�� ���̰� �ϴ� ��
// ����: raw pointer�� �ƴ� ��ü�̴�.
//       ����, ����, ����, �Ҹ��� ��� ������ �߰��� ����� ������ �� �ִ�.
//       ��ǥ���� ���� �Ҹ��ڿ��� �ڿ� ����
// �Ʒ��� �ٽ�
class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = 0) : obj(p) {}
	Car* operator->() { return obj; }
	// Car operator*() { return *obj; } // ����. �Լ��� �� Ÿ���� ��ȯ�ϸ� ���纻�� �����Ǿ ��ȯ�մϴ�.
	Car& operator*() { return *obj; }

	~Ptr() { delete obj; }
};

int main()
{
	Ptr p = new Car; // Ptr p(new Car)
	p->Go(); // (p.operator->())Go() ���������
	         // (p.operator->())->Go()�� �ؼ��˴ϴ�. C++�� Ư¡
	(*p).Go();
}