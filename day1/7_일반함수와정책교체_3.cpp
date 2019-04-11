// 7_�Լ�����å��ü_3
#include <iostream>
#include <algorithm>
using namespace std;

// 1. �Ϲ��Լ��� �ڽŸ��� Ÿ���� �����ϴ�.
//    signiture(��ȯŸ��, ����)�� ������ �Լ��� ���� Ÿ���Դϴ�.

// 2. �Լ� ��ü�� �ڽŸ��� Ÿ���� �ִ�.
//    signiture(��ȯŸ��, ����)�� �����ص� ��� �Լ� ��ü�� �ٸ� Ÿ���̴�.
//    �Լ� ��ü�� inline ġȯ ����

struct Less
{
	inline bool operator()(int a, int b) { return a < b; }
};
struct Greater
{
	inline bool operator()(int a, int b) { return a > b; }
};

// ��å ��ü�� �����ϰ�, ��å�� �ζ��� ġȯ�� �����ϴ� �Լ�
// ���ø��� �Լ���ü�� ����ϴ� ��� - STL�� ���� ����
template<typename T> void Sort(int* x, int sz, T cmp)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			if (cmp(x[i], x[j]))
				swap(x[i], x[j]);
		}
	}
}

int main()
{
	Less f1;     f1(1, 2);
	Greater f2;  f2(1, 2);

	int x[10] = { 1, 3, 5, 6, 9, 2, 4, 6, 8, 10 };
    Sort(x, 10, f1); // ok. f1�� ()������ �Լ� inline ġȯ��
    Sort(x, 10, f2); // 
}