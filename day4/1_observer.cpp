// 1_observer: 94 page
#include <iostream>
#include <vector>
using namespace std;

// �����Ϳ� ��ȭ�� ���� �� ���� ��ü�� �뺸������ -> ���� ������ ��ȯ �� �׷��� ��� ������Ʈ

// ��� �׷����� ������ �������̽�
struct IGraph
{
	virtual void update(int n) = 0;
	virtual ~IGraph() {}
};


// ������ ������ �⺻ ������ �������� ������ ������� �����ϴ�
// ���ϴ� �ڵ�: �����Լ��� ���� �Ļ�Ŭ������ ������ �� �� �ְ�
// ������ �ʴ� �ڵ�: ��� Ŭ������ �����ؼ� ��ӹ޴´�

// ������ ���(Subject ��� �� ���)
class Subject
{
	vector<IGraph*> v;
public:
	void attach(IGraph* g) { v.push_back(g); }
	void detach(IGraph* g) {}
	void notify(int n)
	{
		for (auto p : v)
			p->update(n);
	}

};
class Table : public Subject
{
	int data;
public:
	
	void edit()
	{
		while (1)
		{
			cout << "input data>> ";
			cin >> data;
			notify(data);
		}
	}
};

class BarGraph : public IGraph
{
public:
	virtual void update(int n)
	{
		cout << "BarGraph: ";
		for (int i = 0; i <  n; i++)
			cout << "*";

		cout << endl;
	}
};
class PieGraph : public IGraph
{
public:
	virtual void update(int n)
	{
		cout << "PieGraph: ";
		for (int i = 0; i < n; i++)
			cout << ")";

		cout << endl;
	}
};

int main()
{
	Table t;
	BarGraph bg; t.attach(&bg);
	PieGraph pg; t.attach(&pg);
	t.edit();
}