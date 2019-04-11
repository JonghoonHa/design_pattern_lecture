// 10_메뉴_2

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;

// "Composite 패턴"

// 핵심: 복합객체(PopupMenu)는 개별객체(MenuItem) 뿐 아니라 복합 객체도 보관할 수 있다.
//       복합객체와 개별객체는 동일한 기반 클래스를 사용한다.
//        자신이 자신을 보관 -> 재귀적 포함.

// 복합객체와 개별객체는 사용법이 동일하다. - 메뉴 선택 시 command 호출
// -> command()는 기반 클래스에 있어야 한다.

// 메뉴를 객체지향으로 설계하자.

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