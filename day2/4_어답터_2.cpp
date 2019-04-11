// 4_어답터_2: 75 page
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

class Text : public Shape
{
	TextView* pView;
public:
	// 기존에 존재하는 TextView를 전달받는다
	Text(TextView* p) : pView(p) {}

	void Draw() { pView->show(); }
};

// 상속: 클래스에 대한 확장, 변환, 정적인 작업
// 포함: 객체에 대한 확장, 변환, 동적인 작업

// 클래스 어답터: 클래스의 변경, 상속 사용
// 객체 어답터: 객체의 변경, 포함 사용

int main()
{
	vector<Shape*> v;

	TextView tv("hello");
	// v.push_back(&tv); // error. adapter가 필요하다

	Text t(&tv); // tv를 도형편집기에 넣기 위한 어답터
	v.push_back(&t);

	v[0]->Draw();

}
