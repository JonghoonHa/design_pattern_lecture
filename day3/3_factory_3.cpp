// 3_factory_3: 127page
#include <iostream>
#include <vector>
#include <map>
using namespace std;

ShapeFactory factory;

class Shape
{
public:
	virtual void Draw() { cout << "Draw Shape" << endl; }
};

class ShapeFactory
{
private:
	ShapeFactory() {}
	ShapeFactory(const ShapeFactory&) = delete;
	void operator=(const ShapeFactory&) = delete;
public:
	static ShapeFactory& getInstance()
	{
		static ShapeFactory instance;
		return instance;
	}
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
			p = create_map[type]();

		return p;
	}
};
struct AutoRegister
{
	AutoRegister(int type, Shape*(*f)())
	{
		ShapeFactory& factory = ShapeFactory::getInstance();
		factory.Register(type, f);
	}
};
// AutoRegister r(1, &Rect::Create);



class Rect : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Rect" << endl; }
	static Shape* Create() { return new Rect; }

	// 모든 도형에 자신을 등록하는 static 멤버 데어터가 있어야 한다
	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::Create);

class Circle : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Circle" << endl; }
	static Shape* Create() { return new Circle; }
	static AutoRegister ar;
};
AutoRegister Circle::ar(2, &Circle::Create);

int main()
{
	ShapeFactory& factory = ShapeFactory::getInstance();

	// factory.Register(1, &Rect::Create);
	// factory.Register(2, &Circle::Create);

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

