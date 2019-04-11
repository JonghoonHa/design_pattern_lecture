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

	// �ڽ��� ���� �� �ִ� static ��� �Լ��� ������ �����ϴ�.
	static Shape* Create() { return new Rect; }
};

// Rect�� ����� ���
// 1. new Rect
// 2. Rect::Create()
/*
void foo(Shape*(*f)())
{
	f();
}
foo(&Rect::Create); // �Լ� ���ڷ� ������ �� �ְԵ˴ϴ�.
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
	map<int, CREATOR> create_map; // ��ü ����'�Լ�'�� �����ϴ� map
public:
	void Register(int type, CREATOR f)
	{
		create_map[type] = f;
	}

	Shape* CreateShape(int type)
	{
		Shape* p = nullptr;
		
		if (create_map[type] != nullptr)
			p = create_map[type](); // ��ü ���� (�� Ŭ������ ���� �Լ��� �θ���)

		return p;
	}
};
int main()
{
	ShapeFactory factory;

	// ���忡 ��ǰ�� ����մϴ�.
	factory.Register(1, &Rect::Create);
	factory.Register(2, &Circle::Create);

	// ������ ���ο� ��ǰ�� ������ ���忡 ��ϸ� �ϸ� �˴ϴ�.
	// ����: �� ���� ��ǰ�� �ִ��� ���� �˷��ִ� �Լ��� factory�� ���� ���� �ֽ��ϴ�.
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

