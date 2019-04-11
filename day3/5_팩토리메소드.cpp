// 5_팩토리메소드
#include <iostream>
using namespace std;

// 모든 컨트롤은 인터페이스가 필요하다
struct IEdit {};
struct IButton {};

struct WinEdit : IEdit {};
struct WinButton : IButton {};

struct OSXEdit : IEdit {};
struct OSXButton : IButton {};

// 사용자가 지정한 옵션과 상관없이
// WIndows 모양의 DialogBox를 만드는 클래스
class WinDialog
{
public:
	void Init()
	{
		IEdit* pEdit = new WinEdit;
		IButton* pButton = new WinButton;

		// pEdit->Move(); pButton->Move();
		// pEdit->Draw(); pButton->Draw();
	}
};
class OSXDialog
{
public:
	void Init()
	{
		IEdit* pEdit = new OSXEdit;
		IButton* pButton = new OSXButton;

		// pEdit->Move(); pButton->Move();
		// pEdit->Draw(); pButton->Draw();
	}
};

int main(int argc, char** argv)
{
	
}