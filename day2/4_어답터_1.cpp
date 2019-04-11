// 4_�����_1: 157 page
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// �Ʒ� Ŭ������ �̹� �־��ٰ� �����غ���
class TextView
{
	string data;
public:
	TextView(string s) : data(s) {}

	void show() { cout << data << endl; }
};

class Shape
{
public:
	virtual void Draw() { cout << "Draw Shape" << endl; }
};
class Rect : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Rect" << endl; }
};
class Circle : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Circle" << endl; }
};

// ���������⿡�� ����Ϸ���
// 1. Shape�κ��� �Ļ��Ǿ�� �Ѵ�.
// 2. �׸��� �׸��� �Լ��� Draw()�� �Ǿ�� �Ѵ�.
// TextView�� �������̽��� �����ؼ� ���������⿡�� ��� �����ϰ� �����.

// Adapter pattern: ���� Ŭ������ �������̽�(�Լ� �̸�)�� �����ؼ� �ý����� �䱸�ϴ� Ŭ������ ����� ����
// Ŭ���� �����: Ŭ������ �������̽��� ����, �ַ� ���� ���
class Text : public Shape, public TextView
{
public:
	Text(string s) : TextView(s) {}

	void Draw() { TextView::show(); }
};

int main()
{
	vector<Shape*> v;

	v.push_back(new Rect);
	v.push_back(new Text("hello"));
	v[1]->Draw();

	// TextView tv("hello");
}
