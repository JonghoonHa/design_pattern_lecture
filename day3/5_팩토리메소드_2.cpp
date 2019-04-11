// 5_팩토리메소드_2
#include <iostream>
using namespace std;

// 모든 컨트롤은 인터페이스가 필요하다
struct IEdit {};
struct IButton {};

struct WinEdit : IEdit {};
struct WinButton : IButton {};

struct OSXEdit : IEdit {};
struct OSXButton : IButton {};

// 변하는 것: 가상함수로 만들어서 파생클래스가 재정의
// 변하지 않는 동일한 코드: 기반 클래스를 만들어서 상속받자!!

// Factory Method: 객체를 만들기 위한 인터페이스를 정의하고 사용하지만, 어떤 객체를 만들지는 파생클래스가 결정한다
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

// 사용자가 지정한 옵션과 상관없이 WIndows 모양의 DialogBox를 만드는 클래스
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
// GoF(4명의 이름의 약자)의 패턴은 23개입니다.
// 이중 객체를 생성하는 것에 관련된 패턴은 5개입니다! 192page
// 1. Singleton: 오직 하나의 객체
// 2. Prototype: 객체를 만들 때 복사하면 된다
// 3. Abstract Factory: 객체를 만들 때 추상 팩토리가 있으면 된다.
// 4. Factory Methor:
// 5. Builder: 

// 객체를 만드는 4가지 기술: 118 page
// 1. new Rect
// 2. Rect::Create() -> singleton, flyweight
// 3. sample->Clone()
// 4. factory.Create()