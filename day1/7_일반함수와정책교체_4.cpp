// 7_함수와 정책교체_4

#include <iostream>
#include <algorithm> // 여기에 C++의 sort()함수 있음
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

	// sort는 함수 템플릿입니다.
	
	// 1. 비교정책으로 일반함수를 사용할 때
	// 장점: 정책을 교체해도 sort()함수는 1개이다. 메모리 증가 안함
	// 단점: 정책은 인라인 치환 될 수 없다. 느리다.

	sort(x, x+10, cmp1); // sort(int*, int*, bool(*)(int, int) 인 함수 생성
	sort(x, x+10, cmp2); // sort(int*, int*, bool(*)(int, int) 인 함수 생성

	// 2. 비교정책으로 함수 객체를 사용할 때
	// 장점: 정책이 인라인 치환된다. 빠르다.
	// 단점: 정책을 교체한 횟수 만큼의 sort() 기계어 생성 (코드 메모리 많이 차지함... 그래도 코드 메모리 자체가 얼마 안됨)
	Less    f1;
	Greater f2;
	sort(x, x + 10, f1); // sort(int*, int*, Less) 인 함수 생성
	sort(x, x + 10, f2); // sort(int*, int*, Greater) 인 함수 생성
}
