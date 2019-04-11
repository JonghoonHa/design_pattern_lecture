// 1_decorator_4
#include <iostream>
#include <string>
using namespace std;

// 객체와 기능 추가 객체들의 공통의 기반 클래스를 설계한다.
struct Item
{
	virtual void Draw() = 0;
	virtual ~Item() {}
};
// -------------------------------------------------------

class Picture : public Item
{
	string imgSrc;
public:
	Picture(string src) : imgSrc(src) {}

	void Draw() { cout << "Draw " << imgSrc << endl; }
};
class FrameDecorator : public Item
{
	Item* pic;
public:
	FrameDecorator(Item* p) : pic(p) {}

	void Draw()
	{
		cout << "[[ Frame ]]" << endl;
		pic->Draw();
	}
};
class FlowerDecorator : public Item
{
	Item* pic;
public:
	FlowerDecorator(Item* p) : pic(p) {}

	void Draw()
	{
		cout << "[[ Flower ]]" << endl;
		pic->Draw();
	}
};
int main()
{
	Picture p("family.jpg");
	// p.Draw();
	FrameDecorator fd(&p);
	// fd.Draw();
	FlowerDecorator fl(&fd);
	fl.Draw();
}
