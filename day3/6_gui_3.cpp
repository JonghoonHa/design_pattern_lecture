// 책임의 전가: 170 page
// 6_GUI_3
#include <iostream>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

class Window
{
	int handle;
	static map<int, Window*> this_map; // 윈도우 번호를 키값으로 this를 보관하는 맵
public:
	void Create()
	{
		handle = ec_make_window(&handler);
		this_map[handle] = this; // this를 자료구조에 보관
	}

	static int handler(int hwd, int msg, int a, int b)
	{
		// 자료구조에 보관한 this를 꺼내면 모든 멤버에 접근할 수 있다.
		Window* self = this_map[hwd];

		switch (msg)
		{
		case WM_KEYDOWN:     self->OnKeyDown();    break;
		case WM_LBUTTONDOWN: self->OnLButtonDown(); break;
		}
		return 0;
	}

	virtual void OnKeyDown() {} // OnKeyDown(Window* this)
	virtual void OnLButtonDown() {}
};
map<int, Window*> Window::this_map; // 윈도우 번호를 키값으로 this를 보관하는 맵

int main()
{
	Window w;
	w.Create();
	ec_process_message();
}