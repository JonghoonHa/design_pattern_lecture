// 2_menuevent

#include <iostream>
#include <string>
using namespace std;

class MenuItem
{
	string title;
	int id;
public:
	MenuItem(string s, int n) : title(s), id(n) {}

	virtual void command()
	{
		// 메뉴가 선택된 사실을 외부에 알리고
		// 외부에서 메뉴이벤트를 처리해야 한다
	}
};

int main()
{
	MenuItem m1("HD", 11);
	MenuItem m2("UHD", 12);
	m1.command();
	m2.command();
}
