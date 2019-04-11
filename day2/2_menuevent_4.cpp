// 2_menuevent_4
#include <iostream>
#include <string>
using namespace std;

// 방법 3. 함수 퍼인터 기반의 이벤트 처리
// MFC, QT, C#언어(delegate) 등에서 널리 사용하는 방식
class MenuItem
{
	string title;
	int id;

	void(*handler)();
public:
	void setHandler(void(*f)()) { handler = f; }

	MenuItem(string s, int n) : title(s), id(n) {}

	virtual void command()
	{
		handler();
	}
};
// -----------------------------------------------
void foo() { cout << "foo" << endl; }
void goo() { cout << "goo" << endl; }

class Dialog
{
public:
	void Close() { cout << "Dialog Close" << endl; }
};
int main()
{
	MenuItem m1("HD", 11);
	MenuItem m2("UHD", 12);


	// m1.setHandler(&foo);
	m2.setHandler(&goo); // 객체가 이닌 함수를 등록
	m1.setHandler(&Dialog::Close); //error. 일반함수에 멤버변수의 주소를 담을 수 없다

	m1.command();
	m2.command();
}