// 5_���丮�޼ҵ�_2
#include <iostream>
using namespace std;

// ��� ��Ʈ���� �������̽��� �ʿ��ϴ�
struct IEdit {};
struct IButton {};

struct WinEdit : IEdit {};
struct WinButton : IButton {};

struct OSXEdit : IEdit {};
struct OSXButton : IButton {};

// ���ϴ� ��: �����Լ��� ���� �Ļ�Ŭ������ ������
// ������ �ʴ� ������ �ڵ�: ��� Ŭ������ ���� ��ӹ���!!

// Factory Method: ��ü�� ����� ���� �������̽��� �����ϰ� ���������, � ��ü�� �������� �Ļ�Ŭ������ �����Ѵ�
class BaseDialog
{
public:
	void Init()
	{
		IEdit* pEdit = CreateEdit();
		IButton* pButton = CreateButton();

		// pEdit->Move(); pButton->Move();
		// pEdit->Draw(); pButton->Draw();
	}
	virtual IEdit* CreateEdit() = 0;
	virtual IButton* CreateButton() = 0;
};

// ����ڰ� ������ �ɼǰ� ������� WIndows ����� DialogBox�� ����� Ŭ����
class WinDialog : BaseDialog
{
public:
	IEdit* pEdit = CreateEdit() { return new WinEdit; }
	IButton* pButton = CreateButton() { return new WinButton; }
};
class OSXDialog :  BaseDialog
{
public:
	IEdit* pEdit = CreateEdit() { return new OSXEdit; }
	IButton* pButton = CreateButton() { return new OSXButton; }
};

int main(int argc, char** argv)
{

}
// GoF(4���� �̸��� ����)�� ������ 23���Դϴ�.
// ���� ��ü�� �����ϴ� �Ϳ� ���õ� ������ 5���Դϴ�! 192page
// 1. Singleton: ���� �ϳ��� ��ü
// 2. Prototype: ��ü�� ���� �� �����ϸ� �ȴ�
// 3. Abstract Factory: ��ü�� ���� �� �߻� ���丮�� ������ �ȴ�.
// 4. Factory Methor:
// 5. Builder: 

// ��ü�� ����� 4���� ���: 118 page
// 1. new Rect
// 2. Rect::Create() -> singleton, flyweight
// 3. sample->Clone()
// 4. factory.Create()