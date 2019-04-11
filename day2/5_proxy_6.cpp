// 5_proxy_6

#include <iostream>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

#include "ICalc.h"

int main()
{
	void* addr = ec_load_module("proxy.dll");

	typedef ICalc*(*F)();
	F f = (F)ec_get_function_address(addr, "CreateProxy");
	// ---------------------------------------------------

	ICalc* pCalc = f();

	cout << pCalc->Add(1, 2) << endl;

	ICalc* p = pCalc;
	p->AddRef();

	pCalc->Release();
	cout << "-----" << endl;
	p->Release();

	// delete pCalc; // ���� ����� �Ҵ��� �޸𸮴� ������⿡�� �����ϴ� ���� �����ϴ�.

	// ICalc* p2 = pCalc;

	// ���� ��⿡ ���� �Լ� ȣ��(pCalc);
}
