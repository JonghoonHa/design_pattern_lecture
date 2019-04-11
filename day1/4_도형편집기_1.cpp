// 4_����������_1 - 15 page

#include <iostream>
#include <vector>
using namespace std;

// �Ŀ�����Ʈ ���� ���α׷��� �����غ���~~
// 1. ��� ������ Ÿ��ȭ(Ŭ����)�ϸ� ���ϴ�.
// 2. ������ ��� Ŭ������ ������ ��� ������ ��� ������ �� �ִ�.
// 3. ��� ����(�Ļ�Ŭ����)�� ������ Ư¡�� �ݵ�� ��� Ŭ�������� �־�� �Ѵ�.
//    �׷��� ��� Ŭ���� �����ͷ� �ش� Ư¡�� ����� �� �ִ�.
// 4. �Ļ� Ŭ������ �������ϴ� ��� �Լ��� �ݵ�� �����Լ��� �Ǿ�� �Ѵ�.
//    "�����Լ��� �ƴ� �Լ��� ���������� ����" - C++ �ݾ�
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
			// ��� ������ �׸���
			for (int i = 0; i < v.size(); i++)
				v[i]->Draw();
		}
	}
}