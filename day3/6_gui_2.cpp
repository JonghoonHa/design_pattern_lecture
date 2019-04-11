// 책임의 전가: 170 page
// 6_GUI_2
#include <iostream>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

// GUI 클래스 라이브러리를 만들어보자
class Window
{
	int handle;
public:
	void Create()
	{
		handle = ec_make_window(&handler);
	}

	// 핵심. ec_make_window의 인자로 전달되려면 반스디 함수 인자가 4개여야 한다. 
	//       따라서 아래 함수는 반드시 static 멤버 함수가 되어야 한다.
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