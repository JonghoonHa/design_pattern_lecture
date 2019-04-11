// 7_�Ϲ��Լ��� ��å��ü
#include <iostream>
#include <algorithm>
using namespace std;

// c���ü�� (�Ϲ��Լ�����) ���ϴ� ���� �и��Ϸ��� ���ϴ� ���� �Լ� ���ڷ� �̾Ƴ���. (�Լ� ������ ���)

// C����� qsort()�� ����
void Sort(int* x, int sz, bool(*cmp)(int, int))
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			// if (x[i] > x[j])
			if( cmp(x[i], x[j]) )
				swap(x[i], x[j]);
		}
	}
}
// �� ��å�� ���� ��å �Լ�
bool cmp1(int a, int b) { return a < b; }
bool cmp2(int a, int b) { return a > b; }

int main()
{
	int x[10] = { 1, 3, 5, 6, 9, 2, 4, 6, 8, 10 };
	Sort(x, 10, &cmp1); // �������� ����
	Sort(x, 10, &cmp2); // �������� ����
}