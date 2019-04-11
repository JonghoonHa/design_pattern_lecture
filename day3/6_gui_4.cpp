// 책임의 전가: 170 page
// 6_GUI_4
#include <iostream>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

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

	static int handler(int hwd, int msg, int a, int b)
	{
		Window* self = this_map[hwd];

		switch (msg)
		{
		case WM_KEYDOWN:     self->OnKeyDown();    break;
		case WM_LBUTTONDOWN: self->OnLButtonDown(); break;
		}
		return 0;
	}

	virtual void OnKeyDown() {}
	virtual void OnLButtonDown() {}
};
map<int, Window*> Window::this_map;

// 이 아래에는 라이브러리 사용자 코드입니다.
class MyWindow : public Window
{
public:
	virtual void OnLButtonDown()
	{
		cout << "MyWindow OnLButton" << endl;
	}
	virtual void OnKeyDown()
	{
		cout << "MyWindow KeyDown" << endl;
	}
};

int main()
{
	MyWindow w;
	w.Create();
	ec_process_message();
}