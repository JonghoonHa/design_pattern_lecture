// 5_proxy_3
#include <iostream>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

// ������ �ִ� ��ɰ� proxy�� ������ �̸��� �������Ѵ�.
// �������̽��� ����Ѵ�.

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
	// ������ ����ϴ� ��ü(Proxy)�� �����մϴ�.
	Calc* pCalc = new Calc;
	cout << pCalc->Add(1, 2) << endl;
	cout << pCalc->Sub(1, 2) << endl;
}