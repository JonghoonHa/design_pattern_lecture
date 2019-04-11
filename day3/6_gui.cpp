// 책임의 전가: 170 page
// 6_GUI
#include <iostream>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

int handler(int hwd, int msg, int a, int b)
{
	switch (msg)
	{
	case WM_KEYDOWN:     cout << "keydown" << endl;    break;
	case WM_LBUTTONDOWN: cout << "buttondown" << endl; break;
	}
	return 0;
}

int main()
{
	int h1 = ec_make_window(&handler);
	int h2 = ec_make_window(&handler);

	Color c(255, 0, 0);
	ec_set_window_color(h2, c);

	ec_add_child(h1, h2); // h1에 h2를 자식윈도우로 붙인다

	ec_process_message();
}