// 5_���丮�޼ҵ�
#include <iostream>
using namespace std;

// ��� ��Ʈ���� �������̽��� �ʿ��ϴ�
struct IEdit {};
struct IButton {};

struct WinEdit : IEdit {};
struct WinButton : IButton {};

struct OSXEdit : IEdit {};
struct OSXButton : IButton {};

// ����ڰ� ������ �ɼǰ� �������
// WIndows ����� DialogBox�� ����� Ŭ����
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