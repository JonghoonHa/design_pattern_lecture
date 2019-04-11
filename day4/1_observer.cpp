// 1_observer: 94 page
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


// 관찰자 패턴의 기본 로직은 데이터의 종류에 상관없이 동일하다
// 변하는 코드: 가상함수로 만들어서 파생클래스가 재정의 할 수 있게
// 변하지 않는 코드: 기반 클래스로 제공해서 상속받는다

// 관찰의 대상(Subject 라는 용어를 사용)
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