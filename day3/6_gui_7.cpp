// 책임의 전가: 170 page
// 6_GUI_7
#include <iostream>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

// 템플릿 디자인의 핵심
// 클래스 안에 T를 사용하지 않은 모든 멤버는 템플릿이 아닌 기반 클래스를 설계해서 상속받게 하자

// WTL 라이브러리!

class BaseWindow
{
protected:
	int handle;
	static map<int, BaseWindow*> this_map;
public:
	// 템플릿 인자를 사용하지 않은 모든 멤버들
	void ShowWindow() {}
};
map<int, BaseWindow*> BaseWindow::this_map;

template<typename T> class Window : public BaseWindow
{
public:
	void Create()
	{
		handle = ec_make_window(&handler);
		this_map[handle] = this;
	}

	static int handler(int hwd, int msg, int a, int b)
	{
		T* self = (T*)this_map[hwd];

		switch (msg)
		{
		case WM_KEYDOWN:     self->OnKeyDown();    break;
		case WM_LBUTTONDOWN: self->OnLButtonDown(); break;
		}
		return 0;
	}

	void OnKeyDown() {}
	void OnLButtonDown() {}
};

// 이 아래에는 라이브러리 사용자 코드입니다.
class MyWindow : public Window<MyWindow>
{
public:
	void OnLButtonDown() {cout << "MyWindow OnLButton" << endl;}
	void OnKeyDown() {cout << "MyWindow KeyDown" << endl;}
};

int main()
{
	MyWindow w;
	w.Create();
	ec_process_message();
}