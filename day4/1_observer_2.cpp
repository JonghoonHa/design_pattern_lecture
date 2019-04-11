// 1_observer_2: 94 page
#include <iostream>
#include <vector>
using namespace std;

// 데이터에 변화가 생길 때 여러 객체에 통보해주자 -> 엑셀 데이터 변환 시 그래프 모양 업데이트

// 모든 그래프의 공통의 인터페이스
struct IGraph
{
	virtual void update(int n) = 0;
	virtual ~IGraph() {}
};

class Table
{
	vector<IGraph*> v;
	int data;
public:
	void attach(IGraph* g) { v.push_back(g); }
	void detach(IGraph* g) {}
	void notify(int n)
	{
		// 모든 그래프에 알려준다
		for (auto p : v)
			p->update(n);
	}
	void edit()
	{
		while (1)
		{
			cout << "input data>> ";
			cin >> data;
			// 등록된 모든 그래프(관찰자)에게 알려준다
			notify(data);
		}
	}
};

// 다양한 그래프를 만든다
class BarGraph : public IGraph
{
public:
	virtual void update(int n)
	{
		cout << "BarGraph: ";
		for (int i = 0; i < n; i++)
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