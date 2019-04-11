// å���� ����(170p)
// 6_GUI
#include <iostream>
#include "ecourse.hpp"  // ���� �������� ���� ������ ������ ������
#include <map>
using namespace std;
using namespace ecourse;


class Window;

struct AFX_MSG
{
	int message;
	void(Window::*handler)();
};


class Window
{
	int handle;
	static map<int, Window*> this_map;
public:
	void Create()
	{
		handle = ec_make_window(&handler);
		this_map[handle] = this;
	}
	// �޼��� ó�� ������ ���� �迭�� ��ȯ�ϴ� �����Լ�
	virtual AFX_MSG* GetMessageMap() { return 0; }

	static int handler(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		if (self == 0) return 0;


		AFX_MSG* arr = self->GetMessageMap();
		if (arr == 0) return 0;

		while (arr->message != 0)
		{
			if (arr->message == msg)
			{
				void(Window::*f)() = arr->handler;

				(self->*f)();
			}
			++arr;
		}


		return 0;
	}

};
map<int, Window*> Window::this_map;

#define DECLARE_MESSAGE_MAP()                 \
        virtual AFX_MSG* GetMessageMap();
#define BEGIN_MESSAGE_MAP(classname)          \
        AFX_MSG* classname::GetMessageMap()   \
        {                                     \
            typedef void(Window::*HANDLER)(); \
            static AFX_MSG arr[] = {
#define ADD_MESSAGE(message, handler)         \
            {message, (HANDLER)handler},
#define END_MESSAGE_MAP()                     \
                { 0, 0},                      \
            };                                \
        return arr;                           \
        }

// ���̺귯�� ����� �ڵ� �Դϴ�.
class MyWindow : public Window
{
public:
	void OnLButtonDown() { cout << "MyWindow OnLButton" << endl; }
	void OnKeyDown() { cout << "MyWindow Keydown" << endl; }
	DECLARE_MESSAGE_MAP();
};

BEGIN_MESSAGE_MAP(MyWindow)
ADD_MESSAGE(WM_LBUTTONDOWN, &MyWindow::OnLButtonDown)
ADD_MESSAGE(WM_KEYDOWN, &MyWindow::OnKeyDown)
END_MESSAGE_MAP()

int main()
{
	MyWindow w;
	w.Create();

	ec_process_message();

}
