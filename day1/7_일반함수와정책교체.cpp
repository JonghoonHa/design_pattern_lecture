// 7_일반함수와 정책교체
#include <iostream>
#include <algorithm>
using namespace std;

// c언어체서 (일반함수에서) 변하는 것을 분리하려면 변하는 것을 함수 인자로 뽑아낸다. (함수 포인터 사용)

// C언어의 qsort()의 원리
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
// 비교 정책을 담은 정책 함수
bool cmp1(int a, int b) { return a < b; }
bool cmp2(int a, int b) { return a > b; }

int main()
{
	int x[10] = { 1, 3, 5, 6, 9, 2, 4, 6, 8, 10 };
	Sort(x, 10, &cmp1); // 내림차순 정렬
	Sort(x, 10, &cmp2); // 오름차순 정렬
}