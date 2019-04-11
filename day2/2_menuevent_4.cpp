// 2_menuevent_4
#include <iostream>
#include <string>
using namespace std;

// ��� 3. �Լ� ������ ����� �̺�Ʈ ó��
// MFC, QT, C#���(delegate) ��� �θ� ����ϴ� ���
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
	m2.setHandler(&goo); // ��ü�� �̴� �Լ��� ���
	m1.setHandler(&Dialog::Close); //error. �Ϲ��Լ��� ��������� �ּҸ� ���� �� ����

	m1.command();
	m2.command();
}