// 4_�߻����丮
#include <iostream>
using namespace std;

// ��� ��Ʈ���� �������̽��� �ʿ��ϴ�
struct IEdit {};
struct IButton {};

struct WinEdit : IEdit {};
struct WinButton : IButton{};

struct OSXEdit : IEdit {};
struct OSXButton : IButton {};

int main(int argc, char** argv)
{
	IEdit* edit;
	if (strcmp(argv[0], "OSX") == 0)
		edit = new OSXEdit();
	else
		edit = new WinEdit();
}