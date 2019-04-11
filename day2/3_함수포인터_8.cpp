// 3_�Լ�������_8
#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders; // _1, _2, ... ���� 20������ ����

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}
void goo(int a, int b) { printf("%d, %d\n", a, b); }
void hoo(int a) { printf("%d\n", a); }

class Test
{
public:
	void foo(int a, int b) { printf("%d, %d\n", a, b); }
};
int main()
{
	function<void(int)> f;
	f = &hoo;
	f(10); // ok... hoo(10)

	f = bind(&goo, 3, _1);
	f(10); // goo(3, 10) ��������

	f = bind(&foo, 3, _1, 7, 8);
	f(10); // foo(3, 10, 7, 8 ) ��������

	Test t;
	// ����Լ��� bind�� ���� ��ü�� ���� �����ϰ�, ���� ����
	f = bind(&Test::foo, &t, 3, _1);
	f(10); // t.foo(3, 10);
}

// ���: ���ڰ� int �� ���� �Լ��� �ʿ��ϴ�.
// C���: ���ڰ� �� ���� �Լ��� ��� ����
// C++���: ���ڰ� �� �� �̻��� ��� ������ �Լ� ��� ���� (bind���п�)
