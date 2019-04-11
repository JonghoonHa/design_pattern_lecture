// 1_decorator_2
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
// 상속을 사용한 기능의 추가
// 객체에 기능을 추가하는 것이 아니라 클래스에 기능을 추가하는 것
// 실행시간에 기능추가가 아닌 코드 작성 시 기능 추가
class FrameDecorator : public Picture
{
public:
	FrameDecorator(string s) : Picture(s) {}

	void Draw()
	{
		cout << "[[ Frame ]]" << endl; // 기능을 추가하고
		Picture::Draw();               // 원래 기능을 수행한다
	}
};

int main()
{
	Picture p("family.jpg");
	p.Draw();
	FrameDecorator fd("family.jpg");
	fd.Draw();
}
