// 4_����������_3 - 23 page

#include <iostream>
#include <vector>
using namespace std;

// 8. template method ����
//    ��� Ŭ������ ������ ���� ��ü �帧�� ����(public, non virtual)
//    ���ϴ� �κи� �����Լ��� �и�(private(protected), virtual)
//    �Ļ�Ŭ������ ���ϴ� �͸� ������

//    C++ ������ "NVI" (Non Virtual Interface) ��� �θ��� ���.

class Shape
{
	// ������ ���� �ڵ�(���뼺)���� ���ϴ� �κ�(������)�� ã�Ƽ� �и��ؾ� �Ѵ�.
	// ���ϴ� �κ��� �����Լ��� �и��Ѵ�.
protected:
	Shape() {}
	virtual void DrawImp() = 0;
public:
	virtual void Draw() final // final�� C++11 ���� ������ ����. �������ϸ� ���� �߻�.
		                      // ��, �����Լ����� final�� ���� �� �ִ�.
	{ 
		cout << "Mutex lock" << endl;
		DrawImp();
		cout << "Mutex unlock" << endl;
	}
	virtual Shape* Clone() = 0;
	virtual ~Shape() {} // ��� ��� Ŭ������ ����Ҹ��ڰ� �Ǿ�� �Ѵ�
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

		// �����غ� ����
		// 1. ��ü�� ���������� OCP�� �����ϰ� �� �� ������? 
		// 2. Undo/Redo ����� ������� ��� �ڵ��ؾ� �ұ�?
		// --> Command�������� �ڵ��ϸ� ��~
		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 8)
		{
			cout << "�� ��° ������ �����ұ��? >> ";
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