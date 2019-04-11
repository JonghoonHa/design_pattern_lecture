// 4_visitor_2

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;

// 일반적인 객체지향 프로그램

// 클래스의 추가: 쉽다
// 가상함수의 추가: 어렵다. Shape에 move()를 추가하면 모든 도형 클래스에 move가 있어야한다

class BaseMenu
{
	string title;
public:
	BaseMenu(string s) : title(s) {} // 생성자
	string getTitle() { return title; }

	// 모든 메뉴의 공통의 특징은 기반 클래스에 있어야 한다.
	// 모든 메뉴는 선택될 수 있다.
	virtual void command() = 0; // 핵심! -> 반드시 command를 자식이 만들어야 한다!
};

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(string s, int n) : BaseMenu(s), id(n) {}

	virtual void command()
	{
		cout << getTitle() << " 메뉴가 선택됨" << endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	vector<BaseMenu*> v; // 이 예제의 핵심.. 모든 종류의 메뉴를 담을 수 있다.
public:
	PopupMenu(string s) : BaseMenu(s) {}

	void addMenu(BaseMenu* p) { v.push_back(p); }

	virtual void command()
	{
		while (1)
		{
			system("cls"); // 화면 지우기

			int sz = v.size(); // 메뉴의 개수

			for (int i = 0; i < sz; i++)
				cout << i + 1 << ". " << v[i]->getTitle() << endl;

			cout << sz + 1 << ".상위 메뉴로 " << endl;

			cout << "메뉴를 선택하세요 >>";

			int cmd;
			cin >> cmd;

			if (cmd < 1 || cmd > sz + 1) // 잘못된 입력
				continue;

			if (cmd == sz + 1) // "상위 메뉴로"를 선택
				break;

			// 선택된 메뉴를 실행합니다.
			v[cmd - 1]->command(); // 다형성!! 핵심. 메뉴의 종류를 조사할 필요 없다!!
		}
	}
};

int main()
{
	// MenuItem m("해상도 변경", 11);
	// m.command();

	PopupMenu* menubar = new PopupMenu("MENUBAR");
	PopupMenu* p1 = new PopupMenu("해상도 변경");
	PopupMenu* p2 = new PopupMenu("색상   변경");

	menubar->addMenu(p1);
	menubar->addMenu(p2);

	p1->addMenu(new MenuItem("HD", 11));
	p1->addMenu(new MenuItem("UHD", 12));

	p2->addMenu(new MenuItem("RED", 21));
	p2->addMenu(new MenuItem("BLUE", 22));
	p2->addMenu(new MenuItem("GREEN", 23));

	menubar->command();
}