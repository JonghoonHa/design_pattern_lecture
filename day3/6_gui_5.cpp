// 6_GUI_5
#include <iostream>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

class WIndow;

struct AFX_MSG
{
	int message;
	void(Window::*handler)();
};

class Window
{
	int handle;
	static map<int, Window*> this_map; // static이니까 모든 window에 대한 map 정보가 연결되어있다~~
public:
	void Create()
	{
		handle = ec_make_window(&handler);
		this_map[handle] = this;
	}

	// 메세지 처리 정보를 담은 배열을 반환하는 가상함수
	virtual AFX_MSG* GetMessageMap()
	{
		return 0;
	}

	static int handler(int hwd, int msg, int a, int b)
	{

		Window* self = this_map[hwd];

		if (self == 0) return 0;

		AFX_MSG* arr = self->GetMessageMap();
		if (arr == 0) return 0;

		while (arr->message != 0)
		{
			if (arr->message == msg)
			{
				void(Window::*f)() = arr->handler;

				(self->*f)(); // 객체의 멤버 함수 부르는 방법
			}
			++arr;
		}

		return 0;
	}
};
map<int, Window*> Window::this_map;

// 이 아래에는 라이브러리 사용자 코드입니다.
class MyWindow : public Window
{
public:

	virtual AFX_MSG* GetMessageMap()
	{
		typedef void(Window::HANDLER)();

		static AFX_MSG arr[] = {
			{WM_LBUTTONDOWN, (HANDLER)&MyWindow::OnLButtonDown},
			{WM_KEYDOWN,     (HANDLER)&MyWindow::OnKeyDown},
			{0,              0},
		};
		return arr;
	}

	void OnLButtonDown() { cout << "MyWindow OnLButton" << endl; }
	void OnKeyDown() { cout << "MyWindow KeyDown" << endl; }
};

int main()
{
	MyWindow w;
	w.Create();
	ec_process_message();
}