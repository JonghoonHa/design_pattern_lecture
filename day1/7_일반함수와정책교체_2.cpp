// 7_�Ϲ��Լ�����å��ü_2

#include<iostream>
using namespace std;

// �Լ���ü(function object, functor): ()������ �Լ��� �������ؼ� �Լ�ó�� ��� ������ ��ü
// �� ����ϴ°�?
// Ư�� ��Ȳ���� �Ϲ� �Լ����� �����ϴ�.
struct Plus
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};
int main()
{
	Plus p;
	int n = p(1, 2); // a.operator()(1, 2)

	// a + b;   // a.operator+(b)
	// a - b;   // a.operator-(b)
	// a();     // a.operator()() '�������� �̸��� ��ȣ()' 
	// a(1, 2); // a.operator()(1, 2) �� �ؼ���
}