// å���� ����: 170 page
// 6_GUI_7
#include <iostream>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

// ���ø� �������� �ٽ�
// Ŭ���� �ȿ� T�� ������� ���� ��� ����� ���ø��� �ƴ� ��� Ŭ������ �����ؼ� ��ӹް� ����

// WTL ���̺귯��!

class BaseWindow
{
protected:
	int handle;
	static map<int, BaseWindow*> this_map;
public:
	// ���ø� ���ڸ� ������� ���� ��� �����
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

// �� �Ʒ����� ���̺귯�� ����� �ڵ��Դϴ�.
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