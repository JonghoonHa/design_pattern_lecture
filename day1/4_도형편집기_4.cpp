// 4_도형편집기_4

#include <iostream>
#include <vector>
using namespace std;

class Shape
{
protected:
	virtual void DrawImp()
	{
		cout << "Draw Shape" << endl;
	}
public:
	virtual void Draw() final // final은 C++11 에서 나오는 문법. 재정의하면 에러 발생.
							  // 단, 가상함수에만 final을 붙일 수 있다.
	{
		cout << "Mutex lock" << endl;
		DrawImp();
		cout << "Mutex unlock" << endl;
	}
	virtual Shape* Clone() { return new Shape(*this); }
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

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 8)
		{
			cout << "몇 번째 도형을 복사할까요? >> ";
			int k;
			cin >> k;

			// k번째 도형의 복사본을 만들어서 v에 추가합니다.

			v.push_back(v[k]->Clone());

		}
		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
				v[i]->Draw();
		}
	}
}