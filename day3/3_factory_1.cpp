// 3_factory_1: 127page
#include <iostream>
#include <vector>
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
};
class Circle : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Circle" << endl; }
};

class ShapeFactory
{
public:
	Shape* CreateShape(int type)
	{
		Shape* p = nullptr;
		switch (type)
		{
		case 1: p = new Rect; break;
		case 2: p = new Circle; break;
		}
		return p;
	}
};
int main()
{
	ShapeFactory factory;
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