// 4_�߻����丮_2: 134, 147 page
#include <iostream>
using namespace std;

// ��� ��Ʈ���� �������̽��� �ʿ��ϴ�
struct IEdit {};
struct IButton {};

struct WinEdit : IEdit {};
struct WinButton : IButton {};

struct OSXEdit : IEdit {};
struct OSXButton : IButton {};

struct IFactory
{
	virtual IEdit* CreateEdit() = 0;
	virtual IButton* CreateButton() = 0;
};

// �� ��Ÿ���� ��Ʈ���� �����ϴ� factory
struct WinFactory : IFactory
{
	IEdit* CreateEdit() { return new WinEdit; }
	IButton* CreateButton() { return new WinButton; }
};
struct OSXFactory : IFactory
{
	IEdit* CreateEdit() { return new OSXEdit; }
	IButton* CreateButton() { return new OSXButton; }
};

int main(int argc, char** argv)
{
	IFactory* factory;
	if (strcmp(argv[0], "OSX") == 0)
		factory = new OSXFactory;
	else
		factory = new WinFactory;

	IEdit* pEdit = factory->CreateEdit();
}