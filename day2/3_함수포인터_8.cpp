// 3_함수포인터_8
#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders; // _1, _2, ... 보통 20개까지 가능

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}
void goo(int a, int b) { printf("%d, %d\n", a, b); }
void hoo(int a) { printf("%d\n", a); }

class Test
{
public:
	void foo(int a, int b) { printf("%d, %d\n", a, b); }
};
int main()
{
	function<void(int)> f;
	f = &hoo;
	f(10); // ok... hoo(10)

	f = bind(&goo, 3, _1);
	f(10); // goo(3, 10) 나오도록

	f = bind(&foo, 3, _1, 7, 8);
	f(10); // foo(3, 10, 7, 8 ) 나오도록

	Test t;
	// 멤버함수를 bind할 때는 객체를 먼저 전달하고, 인자 전달
	f = bind(&Test::foo, &t, 3, _1);
	f(10); // t.foo(3, 10);
}

// 결론: 인자가 int 한 개인 함수가 필요하다.
// C언어: 인자가 한 개인 함수만 사용 가능
// C++언어: 인자가 한 개 이상인 모든 종류의 함수 사용 가능 (bind덕분에)
