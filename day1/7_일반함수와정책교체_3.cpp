// 7_함수와정책교체_3
#include <iostream>
#include <algorithm>
using namespace std;

// 1. 일반함수는 자신만의 타입이 없습니다.
//    signiture(반환타입, 인자)가 동일한 함수는 같은 타입입니다.

// 2. 함수 객체는 자신만의 타입이 있다.
//    signiture(반환타입, 인자)가 동일해도 모든 함수 객체는 다른 타입이다.
//    함수 객체의 inline 치환 가능

struct Less
{
	inline bool operator()(int a, int b) { return a < b; }
};
struct Greater
{
	inline bool operator()(int a, int b) { return a > b; }
};

// 정책 교체가 가능하고, 정책의 인라인 치환을 지원하는 함수
// 템플릿과 함수객체를 사용하는 기술 - STL의 설계 원리
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
    Sort(x, 10, f1); // ok. f1의 ()연산자 함수 inline 치환됨
    Sort(x, 10, f2); // 
}