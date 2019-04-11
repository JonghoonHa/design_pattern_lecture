// 4_visitor_2

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;

// �Ϲ����� ��ü���� ���α׷�

// Ŭ������ �߰�: ����
// �����Լ��� �߰�: ��ƴ�. Shape�� move()�� �߰��ϸ� ��� ���� Ŭ������ move�� �־���Ѵ�

class BaseMenu
{
	string title;
public:
	BaseMenu(string s) : title(s) {} // ������
	string getTitle() { return title; }

	// ��� �޴��� ������ Ư¡�� ��� Ŭ������ �־�� �Ѵ�.
	// ��� �޴��� ���õ� �� �ִ�.
	virtual void command() = 0; // �ٽ�! -> �ݵ�� command�� �ڽ��� ������ �Ѵ�!
};

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(string s, int n) : BaseMenu(s), id(n) {}

	virtual void command()
	{
		cout << getTitle() << " �޴��� ���õ�" << endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	vector<BaseMenu*> v; // �� ������ �ٽ�.. ��� ������ �޴��� ���� �� �ִ�.
public:
	PopupMenu(string s) : BaseMenu(s) {}

	void addMenu(BaseMenu* p) { v.push_back(p); }

	virtual void command()
	{
		while (1)
		{
			system("cls"); // ȭ�� �����

			int sz = v.size(); // �޴��� ����

			for (int i = 0; i < sz; i++)
				cout << i + 1 << ". " << v[i]->getTitle() << endl;

			cout << sz + 1 << ".���� �޴��� " << endl;

			cout << "�޴��� �����ϼ��� >>";

			int cmd;
			cin >> cmd;

			if (cmd < 1 || cmd > sz + 1) // �߸��� �Է�
				continue;

			if (cmd == sz + 1) // "���� �޴���"�� ����
				break;

			// ���õ� �޴��� �����մϴ�.
			v[cmd - 1]->command(); // ������!! �ٽ�. �޴��� ������ ������ �ʿ� ����!!
		}
	}
};

int main()
{
	// MenuItem m("�ػ� ����", 11);
	// m.command();

	PopupMenu* menubar = new PopupMenu("MENUBAR");
	PopupMenu* p1 = new PopupMenu("�ػ� ����");
	PopupMenu* p2 = new PopupMenu("����   ����");

	menubar->addMenu(p1);
	menubar->addMenu(p2);

	p1->addMenu(new MenuItem("HD", 11));
	p1->addMenu(new MenuItem("UHD", 12));

	p2->addMenu(new MenuItem("RED", 21));
	p2->addMenu(new MenuItem("BLUE", 22));
	p2->addMenu(new MenuItem("GREEN", 23));

	menubar->command();
}