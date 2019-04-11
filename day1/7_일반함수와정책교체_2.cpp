// 7_일반함수와정책교체_2

#include<iostream>
using namespace std;

// 함수객체(function object, functor): ()연산자 함수를 재정의해서 함수처럼 사용 가능한 객체
// 왜 사용하는가?
// 특정 상황에서 일반 함수보다 빠릅니다.
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
	// a();     // a.operator()() '연산자의 이름이 괄호()' 
	// a(1, 2); // a.operator()(1, 2) 로 해석됨
}