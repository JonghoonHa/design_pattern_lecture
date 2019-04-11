// proxy
#include <iostream>
#include "ecourse.hpp"
#include "ICalc.h"
using namespace std;
using namespace ecourse;

class Calc : public ICalc

{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

// ���� ��� �ȿ� ��յ� �Լ��� �����ؾ��մϴ�.
// �� �Լ����� proxy�� �����ؼ� �������̽� �����ͷ� ��ȯ�ؾ��մϴ�.
extern "C" __declspec(dllexport)  // windows dll ���� �� �ʿ�
ICalc* CreateProxy()
{
	return new Calc;
}

// ���� �ϴ� ��: cl proxy.cpp /LD    /LD�� DLL�� ������ �ɼ�