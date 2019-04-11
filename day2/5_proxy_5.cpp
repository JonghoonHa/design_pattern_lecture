// 5_proxy_5

#include <iostream>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

// 이제 클라이언트 제작자는 서버 제작자엑서 2개의 파일을 받아야 합니다.
// Icalc.h        : 인터페이스가 담긴 헤더
// Proxy.dll(.so) : proxy가 담긴 동적 모듈
#include "ICalc.h"

int main()
{
	// 동적 모듈을 load하고 모듈에서 약속된 함수 찾기
	void* addr = ec_load_module("proxy.dll"); //dl_open()

	typedef ICalc*(*F)();
	F f = (F)ec_get_function_address(addr, "CreateProxy");
	// ---------------------------------------------------

	ICalc* pCalc = f();

	cout << pCalc->Add(1, 2) << endl;
}
// proxy를 update하려면
// 1. 동적 모듈의 이름(proxy.dll)은 반드시 동일해야 한다.
// 2. 동적 모듈 안에는 "CreateProxy" 함수가 반드시 있어야 한다.
