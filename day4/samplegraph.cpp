// samplegraph

#include <iostream>
using namespace std;

struct IGraph
{
	virtual void update(int n) = 0;
	virtual ~IGraph() {}
};

class SampleGraph : public IGraph
{
public:
	virtual void update(int n)
	{
		cout << "SampleGraph: ";
		for (int i = 0; i < n; i++)
			cout << "+";

		cout << endl;
	}
};

// ���� ��� ����ڴ� ���� ��� �ȿ��ִ� Ŭ������ �̸��� ���� ���մϴ�
// �̸��� �𸣸� ��ü�� ���� �� �����ϴ�
// ���� ��� ��ü���� ��ü�� ����� �Լ��� ��ӵǾ�� �մϴ�.
extern "C" __declspec(dllexport)  // ������ ȯ�濡���� �ʿ�
IGraph* CreateGraph()
{
	return new SampleGraph;
}

// cl SampleGraph.cpp /LD �� ��������~