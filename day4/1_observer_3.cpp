// 1_observer_3: 94 page
#include <iostream>
#include <vector>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

struct IGraph
{
	virtual void update(int n) = 0;
	virtual ~IGraph() {}
};

class Subject
{
	vector<IGraph*> v;
public:
	Subject() 
	{
		// 약속된 폴더에 있는 DLL을 열거한다
		ec_enum_files("C:\\Users\\MOBIS\\source\\pattern\\day4\\GRAPH", "*.dll", LoadModule, this);
	}
	static int LoadModule(string file, void* param)
	{
		cout << file << "찾음" << endl;

		// DLL을 로드하고, 약속된 함수를 찾아서 그래프 생성
		void* addr = ec_load_module(file);

		typedef IGraph*(*F)();
		F f = (F)ec_get_function_address(addr, "CreateGraph");

		IGraph* g = f();

		// 그래프를 부착하자
		// attach(g) // static은 this가 없어서 error
		Subject* self = static_cast<Subject*>(param);
		self->attach(g);

		return 1; // 계속 찾으라는 의미. 0을 반환하면 중지

	}
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