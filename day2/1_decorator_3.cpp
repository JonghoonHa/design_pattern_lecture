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
// ���: Ŭ������ ��� �߰�, �ڵ� �ۼ� �� �߰�
// ����: ��ü�� ��� �߰�, ���� �� ��� �߰�
class FrameDecorator
{
	Picture* pic;
public:
	FrameDecorator(Picture* p) : pic(p) {}

	void Draw()
	{
		cout << "[[ Frame ]]" << endl; // ����߰�
		pic->Draw();                   // ���� ��� ����
	}
};
int main()
{
	Picture p("family.jpg");
	p.Draw();
	FrameDecorator fd(&p); // ��ü p�� ����� �߰��Ѵ�.
	fd.Draw();
}
