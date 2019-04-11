// 3_factory_4: 127page
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


#define REGISTER_SHAPE(classname)    \
        static Shape * Create();     \
        static AutoRegister ar;

#define REGISTER_IMPLEMENT(type, classname)     \
        Shape* classname::Create()              \
        { return new classname; }               \
                                                \
        AutoRegister classname::ar(type, &classname::Create);

class Rect : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Rect" << endl; }
	REGISTER_SHAPE();
};
REGISTER_IMPLEMENT(1, Rect);

class Circle : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Circle" << endl; }
	REGISTER_SHAPE();
};
REGISTER_IMPLEMENT(2, Circle);

int main()
{
	ShapeFactory& factory = ShapeFactory::getInstance();

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

