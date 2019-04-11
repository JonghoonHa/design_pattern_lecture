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

// 동적 모듈 사용자는 동적 모듈 안에있는 클래스의 이름을 알지 못합니다
// 이름을 모르면 객체를 만들 수 없습니다
// 동적 모듈 자체에서 객체를 만드는 함수가 약속되어야 합니다.
extern "C" __declspec(dllexport)  // 윈도우 환경에서만 필요
IGraph* CreateGraph()
{
	return new SampleGraph;
}

// cl SampleGraph.cpp /LD 로 빌드하자~