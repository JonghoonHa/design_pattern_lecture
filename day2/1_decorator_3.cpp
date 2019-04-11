// 1_decorator_3
#include <iostream>
#include <string>
using namespace std;

class Picture
{
	string imgSrc;
public:
	Picture(string src) : imgSrc(src) {}

	void Draw() { cout << "Draw " << imgSrc << endl; }
};
// 상속: 클래스에 기능 추가, 코드 작성 시 추가
// 포함: 객체에 기능 추가, 실행 시 기능 추가
class FrameDecorator
{
	Picture* pic;
public:
	FrameDecorator(Picture* p) : pic(p) {}

	void Draw()
	{
		cout << "[[ Frame ]]" << endl; // 기능추가
		pic->Draw();                   // 원래 기능 수행
	}
};
int main()
{
	Picture p("family.jpg");
	p.Draw();
	FrameDecorator fd(&p); // 객체 p에 기능을 추가한다.
	fd.Draw();
}
