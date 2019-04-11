// 3_함수포인터_6
#include <iostream>
#include <functional>
using namespace std;

class Dialog
{
public:
	void close() { cout << "Dialog Close" << endl; }
};
void foo() { cout << "foo" << endl; }

// C++11부터 지원하는 일반화된 함수 포인터 function
int main()
{
	function<void()> f; // 함수의 주소를 담았다가 호출할 때 사용

	f = &foo;
	f(); // 결국 foo()

	Dialog dlg;
	f = bind(&Dialog::close, &dlg); // '3_함수포인터_5'에서 만든 aciton과 비슷한 기능
	f();
}