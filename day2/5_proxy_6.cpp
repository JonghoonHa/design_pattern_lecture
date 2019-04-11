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

	// delete pCalc; // 동적 모듈이 할당한 메모리는 동적모듈에서 제거하는 것이 좋습니다.

	// ICalc* p2 = pCalc;

	// 동적 모듈에 있응 함수 호출(pCalc);
}
