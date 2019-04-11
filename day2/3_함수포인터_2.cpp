// 3_함수포인터_2
#include <iostream>

// 1. 일반함수 포인터에 멤버함수의 주소를 담을 수 없다. this의 존재 때문
// 2. 일반함수 포인터에 static 멤버함수의 주소를 담을 수 없다.
// 3. 멤버 함수의 주소를 담는 포인터 만드는 방법
// 4. 멤버 함수 포인터를 사용해서 함수를 호출하는 방법 '.*'연산자! 32줄 보자~

class Dialog
{
public:
	void close() {}
};
void foo() {}

int main()
{
	void(*f1)() = &foo; // ok
	// void(*f2)() = &Dialog::close; // error. this 인자가 숨어있어서 만들면 오류가 남!!

	void(Dialog::*f2)() = &Dialog::close; //ok
	printf("%p\n", f2);

	// f2(); // error. 객체(this)가 없습니다.

	Dialog dlg;
	// dlg.f2(); // error. f2는 멤버 함수가 아닌 함수포인터다. f2라는 멤버는 없다.

	// dlg.*f2(); // '.*' : pointer to member 라는 C++이 추가한 연산자
	              // '.*' 보다 ()가 우선순위가 높다. error

	(dlg.*f2)(); // ok.. dlg.close()의 의미와 같다.
}