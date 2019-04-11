// 7_�Ϲ��Լ�����å��ü_5
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

int main()
{
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	sort(x, x + 10); // ����å�� �������� ������ ��������

	// STL �Լ��� ��å ��ü ���
	// 1. �Ϲ� �Լ�
	// sort(x, x + 10, cmp1);

	// 2. �Լ� ��ü
	less<int> f1; //C++ǥ�� (1998�� 1�� ǥ�غ���)���� ����
	sort(x, x + 10, f1);

	// 3. ����ǥ���� ��� - C++11 ���� ����
	sort(x, x + 10, [](int a, int b) { return a < b; });

	// 1��   : �ζ��� ġȯ �ȵ�
	// 2, 3��: �ζ��� ġȯ��
}