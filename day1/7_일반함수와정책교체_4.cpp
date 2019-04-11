// 7_�Լ��� ��å��ü_4

#include <iostream>
#include <algorithm> // ���⿡ C++�� sort()�Լ� ����
using namespace std;

bool cmp1(int a, int b) { return a < b; }
bool cmp2(int a, int b) { return a > b; }

struct Less
{
	inline bool operator()(int a, int b) { return a < b; }
};
struct Greater
{
	inline bool operator()(int a, int b) { return a > b; }
};

int main()
{
	int x[10] = { 1, 3, 5, 6, 9, 2, 4, 6, 8, 10 };

	// sort�� �Լ� ���ø��Դϴ�.
	
	// 1. ����å���� �Ϲ��Լ��� ����� ��
	// ����: ��å�� ��ü�ص� sort()�Լ��� 1���̴�. �޸� ���� ����
	// ����: ��å�� �ζ��� ġȯ �� �� ����. ������.

	sort(x, x+10, cmp1); // sort(int*, int*, bool(*)(int, int) �� �Լ� ����
	sort(x, x+10, cmp2); // sort(int*, int*, bool(*)(int, int) �� �Լ� ����

	// 2. ����å���� �Լ� ��ü�� ����� ��
	// ����: ��å�� �ζ��� ġȯ�ȴ�. ������.
	// ����: ��å�� ��ü�� Ƚ�� ��ŭ�� sort() ���� ���� (�ڵ� �޸� ���� ������... �׷��� �ڵ� �޸� ��ü�� �� �ȵ�)
	Less    f1;
	Greater f2;
	sort(x, x + 10, f1); // sort(int*, int*, Less) �� �Լ� ����
	sort(x, x + 10, f2); // sort(int*, int*, Greater) �� �Լ� ����
}
