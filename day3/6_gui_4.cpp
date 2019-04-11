// å���� ����: 170 page
// 6_GUI_4
#include <iostream>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

class Window
{
	int handle;
	static map<int, Window*> this_map; // static�̴ϱ� ��� window�� ���� map ������ ����Ǿ��ִ�~~
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

// �� �Ʒ����� ���̺귯�� ����� �ڵ��Դϴ�.
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