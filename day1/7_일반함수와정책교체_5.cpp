// 7_일반함수와정책교체_5
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

int main()
{
	int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	sort(x, x + 10); // 비교정책을 전달하지 않으면 오름차순

	// STL 함수의 정책 교체 기술
	// 1. 일반 함수
	// sort(x, x + 10, cmp1);

	// 2. 함수 객체
	less<int> f1; //C++표준 (1998년 1차 표준부터)에서 제공
	sort(x, x + 10, f1);

	// 3. 람다표현식 사용 - C++11 부터 제공
	sort(x, x + 10, [](int a, int b) { return a < b; });

	// 1번   : 인라인 치환 안됨
	// 2, 3번: 인라인 치환됨
}