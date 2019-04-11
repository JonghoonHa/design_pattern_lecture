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
// ����� ����� ����� �߰�
// ��ü�� ����� �߰��ϴ� ���� �ƴ϶� Ŭ������ ����� �߰��ϴ� ��
// ����ð��� ����߰��� �ƴ� �ڵ� �ۼ� �� ��� �߰�
class FrameDecorator : public Picture
{
public:
	FrameDecorator(string s) : Picture(s) {}

	void Draw()
	{
		cout << "[[ Frame ]]" << endl; // ����� �߰��ϰ�
		Picture::Draw();               // ���� ����� �����Ѵ�
	}
};

int main()
{
	Picture p("family.jpg");
	p.Draw();
	FrameDecorator fd("family.jpg");
	fd.Draw();
}
