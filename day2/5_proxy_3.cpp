// 5_proxy_3
#include <iostream>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

// 서버에 있는 기능과 proxy는 동일한 이름을 가져야한다.
// 인터페이스로 약속한다.

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
int main()
{
	// 서버를 대신하는 객체(Proxy)를 생성합니다.
	Calc* pCalc = new Calc;
	cout << pCalc->Add(1, 2) << endl;
	cout << pCalc->Sub(1, 2) << endl;
}