// 4_추상팩토리
#include <iostream>
using namespace std;

// 모든 컨트롤은 인터페이스가 필요하다
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