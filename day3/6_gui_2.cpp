// å���� ����: 170 page
// 6_GUI_2
#include <iostream>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

// GUI Ŭ���� ���̺귯���� ������
class Window
{
	int handle;
public:
	void Create()
	{
		handle = ec_make_window(&handler);
	}

	// �ٽ�. ec_make_window�� ���ڷ� ���޵Ƿ��� �ݽ��� �Լ� ���ڰ� 4������ �Ѵ�. 
	//       ���� �Ʒ� �Լ��� �ݵ�� static ��� �Լ��� �Ǿ�� �Ѵ�.
	static int handler(int hwd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_KEYDOWN:     cout << "keydown" << endl;    break;
		case WM_LBUTTONDOWN: cout << "buttondown" << endl; break;
		}
		return 0;
	}
};

int main()
{
	Window w;
	w.Create(); 
	ec_process_message();
}