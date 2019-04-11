// 5_proxy_2
#include <iostream>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

// �������� ����(IPC �Ǵ� ��Ʈ��ũ ����)�� ����ϴ� Ŭ����
// remote proxy
// proxy�� �Լ� ȣ���� ����ڵ�� �����ؼ� ������ �����մϴ�.
// stub�� ������ ����ڵ带 �ٽ� �Լ� ȣ��� ����

// ����
// 1. IPC�� ���� ������ �� �ʿ� ����.
// 2, Cache ���� �߰� ����� ������ �� �ִ�.
// 3. RPC(Remote Procedure Call), RMI(Remote Method Invocation)�� ����� ��!
class Calc
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