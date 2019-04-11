// 4_도형편집기_3 - 23 page

#include <iostream>
#include <vector>
using namespace std;

// 8. template method 패턴
//    기반 클래스가 변하지 않은 전체 흐름을 제공(public, non virtual)
//    변하는 부분만 가상함수로 분리(private(protected), virtual)
//    파생클래스는 변하는 것만 재정의

//    C++ 에서는 "NVI" (Non Virtual Interface) 라고도 부르는 기술.

class Shape
{
	// 변하지 않은 코드(공통성)에서 변하는 부분(가변성)을 찾아서 분리해야 한다.
	// 변하는 부분을 가상함수로 분리한다.
protected:
	Shape() {}
	virtual void DrawImp() = 0;
public:
	virtual void Draw() final // final은 C++11 에서 나오는 문법. 재정의하면 에러 발생.
		                      // 단, 가상함수에만 final을 붙일 수 있다.
	{ 
		cout << "Mutex lock" << endl;
		DrawImp();
		cout << "Mutex unlock" << endl;
	}
	virtual Shape* Clone() = 0;
	virtual ~Shape() {} // 모든 기반 클래스는 가상소멸자가 되어야 한다
};
class Rect : public Shape
{
public:
protected:
	virtual void DrawImp() override { cout << "Draw Rect" << endl; }
	virtual Shape* Clone() { return new Rect(*this); }
};
class Circle : public Shape
{
public:
protected:
	virtual void DrawImp() override { cout << "Draw Circle" << endl; }
	virtual Shape* Clone() { return new Circle(*this); }
};
class Triangle : public Shape
{
public:
protected:
	virtual void DrawImp() override { cout << "Draw Triangle" << endl; }
	virtual Shape* Clone() { return new Triangle(*this); }
};
int main()
{
	vector<Shape*> v;

	while (1)
	{
		int cmd;
		cin >> cmd;

		// 생각해볼 문제
		// 1. 객체의 생성과정을 OCP를 만족하게 할 수 없을까? 
		// 2. Undo/Redo 기능을 만드려면 어떻게 코딩해야 할까?
		// --> Command패턴으로 코딩하면 됨~
		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 8)
		{
			cout << "몇 번째 도형을 복사할까요? >> ";
			int k;
			cin >> k;

			v.push_back(v[k]->Clone());
		}
		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
				v[i]->Draw();
		}
	}
}