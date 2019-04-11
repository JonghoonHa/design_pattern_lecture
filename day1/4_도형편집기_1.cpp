// 4_도형편집기_1 - 15 page

#include <iostream>
#include <vector>
using namespace std;

// 파워포인트 같은 프로그램을 생각해보자~~
// 1. 모든 도형을 타입화(클래스)하면 편리하다.
// 2. 공통의 기반 클래스가 있으면 모든 도형을 묶어서 관리할 수 있다.
// 3. 모든 도형(파생클래스)의 공통의 특징은 반드시 기반 클래스에도 있어야 한다.
//    그래야 기반 클래스 포인터로 해당 특징을 사용할 수 있다.
// 4. 파생 클래스가 재정의하는 모든 함수는 반드시 가상함수가 되어야 한다.
//    "가상함수가 아는 함수를 재정의하지 말라" - C++ 격언
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
int main()
{
	vector<Shape*> v;

	while (1)
	{
		int cmd;
		cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			// 모든 도형을 그린다
			for (int i = 0; i < v.size(); i++)
				v[i]->Draw();
		}
	}
}