// 4_����������_2 - 15 page

#include <iostream>
#include <vector>
using namespace std;

// 5. ������ ���(�����Լ�)�� �ڵ�� OCP�� �����Ѵ�.
// 6. ��ü���� �����Ģ: ~ �� ���Ѷ�. 5�� ��Ģ
//    ������ ����: ~ ��Ű���� �̷� ������� �ڵ��ض�. - 23���� ����
// 7. Prototype ����: ��ü�� ���� ��, �ߺ��� �����, �ߺ��� ���縦 ���ؼ� ��ü�� ����� ����. 
//                    Clone()�����Լ�. C#���� ��κ� Ŭ������ Clone()�Լ��� �ֽ��ϴ�.
//                    swift ���� copy()��� �Լ��� �ֽ��ϴ�.

class Shape
{
public:
	virtual void Draw() { cout << "Draw Shape" << endl; }
	
	// �ڽ��� ���纻�� ����� �����Լ��� �׻� ���ϴ�
	virtual Shape* Clone() { return new Shape(*this); }
};
class Rect : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Rect" << endl; }
	virtual Shape* Clone() { return new Rect(*this); }
};
class Circle : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Circle" << endl; }
	virtual Shape* Clone() { return new Circle(*this); }
};
class Triangle : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Triangle" << endl; }
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
			cout << "�� ��° ������ �����ұ��? >> ";
			int k;
			cin >> k;

			// k��° ������ ���纻�� ���� v�� �߰��մϴ�.

			v.push_back(v[k]->Clone()); // ok. �������� Ȱ��. OCP�� �����ϴ� ���� �ڵ�
			
		}
		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
				v[i]->Draw(); // ������(polymorphism). ���� �Լ��� ȣ���� ����� ��Ȳ�� ���� �ٸ� �Լ��� ȣ���ϴ� ��. OCP�� �����ϴ� ���� ����!
		}
	}
}