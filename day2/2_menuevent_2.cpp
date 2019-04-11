// 2_menuevent_2
#include <iostream>
#include <string>
using namespace std;

// 방법 1. 가상함수를 사용하는 방식
// 단점: 메뉴 객체를 너무 많이 만들게된다.
// 각 메뉴 당 한 개의 파생 클래스를 만들어야한다. 너무나 많은 파생클래스가 만들어진다. (메뉴 100개면 클래스 100개...ㄷㄷ)
// "template method"는 결국 파생 클래스가 증가한다.
class MenuItem
{
	string title;
	int id;
public:
	MenuItem(string s, int n) : title(s), id(n) {}

	virtual void command()
	{
		OnCommand();
	}
	virtual void OnCommand() = 0;
};

class HDMenu : public MenuItem
{
public:
	HDMenu(string title, int n) : MenuItem(title, n) {}

	virtual void OnCommand() { cout << "메뉴 처리" << endl; }
};

int main()
{
	HDMenu m1("HD", 11);
	// MenuItem m2("UHD", 12);
	m1.command();
	// m2.command();
}
