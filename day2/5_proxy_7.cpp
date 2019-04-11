// 5_proxy_7
#include <iostream>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

#include "ICalc.h"
#include "smartptr.h"

int main()
{
	void* addr = ec_load_module("proxy.dll");

	typedef ICalc*(*F)();
	F f = (F)ec_get_function_address(addr, "CreateProxy");
	// ---------------------------------------------------

	Ptr<ICalc> pCalc = f();

	cout << pCalc->Add(1, 2) << endl;

	Ptr<ICalc> p = pCalc;
}
