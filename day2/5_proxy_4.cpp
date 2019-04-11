// 4_proxy_4
#include <iostream>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

class Calc : public ICalc

{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};
// Proxy 를 만드는 사람은 누구일까요?
// 1. 서버 제작자
// 2. 서버에 접속하고싶은 클라이언트 제작자

int main()
{
	// 클라이언트 제작자는 proxy의 클래스 이름을 사용하면 안됩니다.
	// 강한 결합으로 OCP를 만족할 수 없습니다.
	// Calc* pCalc = new Calc;

	ICalc* pCalc = new Calc;

	cout << pCalc->Add(1, 2) << endl;
	cout << pCalc->Sub(1, 2) << endl;
}