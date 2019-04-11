// å���� ����: 170 page
// 6_GUI_3
#include <iostream>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

class Window
{
	int handle;
	static map<int, Window*> this_map; // ������ ��ȣ�� Ű������ this�� �����ϴ� ��
public:
	void Create()
	{
		handle = ec_make_window(&handler);
		this_map[handle] = this; // this�� �ڷᱸ���� ����
	}

	static int handler(int hwd, int msg, int a, int b)
	{
		// �ڷᱸ���� ������ this�� ������ ��� ����� ������ �� �ִ�.
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
map<int, Window*> Window::this_map; // ������ ��ȣ�� Ű������ this�� �����ϴ� ��

int main()
{
	Window w;
	w.Create();
	ec_process_message();
}