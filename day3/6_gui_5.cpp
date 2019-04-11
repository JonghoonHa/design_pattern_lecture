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
	static map<int, Window*> this_map; // static�̴ϱ� ��� window�� ���� map ������ ����Ǿ��ִ�~~
public:
	void Create()
	{
		handle = ec_make_window(&handler);
		this_map[handle] = this;
	}

	// �޼��� ó�� ������ ���� �迭�� ��ȯ�ϴ� �����Լ�
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

				(self->*f)(); // ��ü�� ��� �Լ� �θ��� ���
			}
			++arr;
		}

		return 0;
	}
};
map<int, Window*> Window::this_map;

// �� �Ʒ����� ���̺귯�� ����� �ڵ��Դϴ�.
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