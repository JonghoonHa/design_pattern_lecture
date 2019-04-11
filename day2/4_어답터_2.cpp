// 4_�����_2: 75 page
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

class Text : public Shape
{
	TextView* pView;
public:
	// ������ �����ϴ� TextView�� ���޹޴´�
	Text(TextView* p) : pView(p) {}

	void Draw() { pView->show(); }
};

// ���: Ŭ������ ���� Ȯ��, ��ȯ, ������ �۾�
// ����: ��ü�� ���� Ȯ��, ��ȯ, ������ �۾�

// Ŭ���� �����: Ŭ������ ����, ��� ���
// ��ü �����: ��ü�� ����, ���� ���

int main()
{
	vector<Shape*> v;

	TextView tv("hello");
	// v.push_back(&tv); // error. adapter�� �ʿ��ϴ�

	Text t(&tv); // tv�� ���������⿡ �ֱ� ���� �����
	v.push_back(&t);

	v[0]->Draw();

}
