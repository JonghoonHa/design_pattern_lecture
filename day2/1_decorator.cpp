// 1_decorator - 65page
#include <iostream>
#include <string>
using namespace std;

class Picture
{
	string imgSrc;
public:
	Picture(string src) : imgSrc(src) {}

	void Draw() { cout << "Draw" << imgSrc << endl; }
};

int main()
{
	Picture p("family.jpg");
	p.Draw();
}
