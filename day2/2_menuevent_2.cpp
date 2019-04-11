// 2_menuevent_2
#include <iostream>
#include <string>
using namespace std;

// ��� 1. �����Լ��� ����ϴ� ���
// ����: �޴� ��ü�� �ʹ� ���� ����Եȴ�.
// �� �޴� �� �� ���� �Ļ� Ŭ������ �������Ѵ�. �ʹ��� ���� �Ļ�Ŭ������ ���������. (�޴� 100���� Ŭ���� 100��...����)
// "template method"�� �ᱹ �Ļ� Ŭ������ �����Ѵ�.
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

	virtual void OnCommand() { cout << "�޴� ó��" << endl; }
};

int main()
{
	HDMenu m1("HD", 11);
	// MenuItem m2("UHD", 12);
	m1.command();
	// m2.command();
}
