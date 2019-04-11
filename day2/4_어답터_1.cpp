// 4_어답터_1: 157 page
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 아래 클래스가 이미 있었다고 가정해보자
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

// 도형편집기에서 사용하려면
// 1. Shape로부터 파생되어야 한다.
// 2. 그림을 그리는 함수는 Draw()가 되어야 한다.
// TextView의 인터페이스를 변경해서 도형편집기에서 사용 가능하게 만든다.

// Adapter pattern: 기존 클래스의 인터페이스(함수 이름)을 변경해서 시스템이 요구하는 클래스를 만드는 패턴
// 클래스 어답터: 클래스의 인터페이스를 변경, 주로 다중 상속
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
