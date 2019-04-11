// 3_함수포인터_7

#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders; // _1, _2, ... 보통 20개까지 가능

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}
int main()
{
	// bind() : N항 함수(함수 객체)를 M항으로 변경하는 도구
	foo(1, 2, 3, 4); 
	bind(&foo, 5, 6, 7, 8)(); // 4항 -> 0항
	bind(&foo, 5, _1, 7, _2)(3, 8); // 4항 -> 2항

	bind(&foo, _3, _1, _2, 5)(7, 9, 3); // 3, 7, 9, 5 나오게 하자
	                                     // 4항 -> 3항 함수로
}