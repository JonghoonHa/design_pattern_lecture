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
		// �޴��� ���õ� ����� �ܺο� �˸���
		// �ܺο��� �޴��̺�Ʈ�� ó���ؾ� �Ѵ�
	}
};

int main()
{
	MenuItem m1("HD", 11);
	MenuItem m2("UHD", 12);
	m1.command();
	m2.command();
}
