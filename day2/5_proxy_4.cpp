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
// Proxy �� ����� ����� �����ϱ��?
// 1. ���� ������
// 2. ������ �����ϰ���� Ŭ���̾�Ʈ ������

int main()
{
	// Ŭ���̾�Ʈ �����ڴ� proxy�� Ŭ���� �̸��� ����ϸ� �ȵ˴ϴ�.
	// ���� �������� OCP�� ������ �� �����ϴ�.
	// Calc* pCalc = new Calc;

	ICalc* pCalc = new Calc;

	cout << pCalc->Add(1, 2) << endl;
	cout << pCalc->Sub(1, 2) << endl;
}