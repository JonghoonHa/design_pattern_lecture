// 3_factory_2: 127page
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Shape
{
public:
	virtual void Draw() { cout << "Draw Shape" << endl; }
};
class Rect : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Rect" << endl; }

	// 자신을 만들 수 있는 static 멤버 함수는 장점이 많습니다.
	static Shape* Create() { return new Rect; }
};

// Rect를 만드는 방법
// 1. new Rect
// 2. Rect::Create()
/*
void foo(Shape*(*f)())
{
	f();
}
foo(&Rect::Create); // 함수 인자로 전달할 수 있게됩니다.
*/
class Circle : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Circle" << endl; }
	static Shape* Create() { return new Circle; }
};

class ShapeFactory
{
	typedef Shape*(*CREATOR)();
	map<int, CREATOR> create_map; // 객체 생성'함수'를 보관하는 map
public:
	void Register(int type, CREATOR f)
	{
		create_map[type] = f;
	}

	Shape* CreateShape(int type)
	{
		Shape* p = nullptr;
		
		if (create_map[type] != nullptr)
			p = create_map[type](); // 객체 생성 (각 클래스의 생성 함수를 부른다)

		return p;
	}
};
int main()
{
	ShapeFactory factory;

	// 공장에 제품을 등록합니다.
	factory.Register(1, &Rect::Create);
	factory.Register(2, &Circle::Create);

	// 앞으로 새로운 제품이 나오면 공장에 등록만 하면 됩니다.
	// 장점: 몇 개의 제품이 있는지 등을 알려주는 함수를 factory에 만들 수도 있습니다.
	vector<Shape*> v;

	while (1)
	{
		int cmd;
		cin >> cmd;

		if (cmd > 0 && cmd < 7)
		{
			Shape* p = factory.CreateShape(cmd);

			if (p != nullptr)
				v.push_back(p);
		}
		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
				v[i]->Draw();
		}
	}
}

