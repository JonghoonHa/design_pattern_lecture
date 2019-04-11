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

// 동적 모듈 안에 약손된 함수를 제공해야합니다.
// 이 함수에서 proxy를 생성해서 인터페이스 포인터로 반환해야합니다.
extern "C" __declspec(dllexport)  // windows dll 만들 때 필요
ICalc* CreateProxy()
{
	return new Calc;
}

// 빌드 하는 법: cl proxy.cpp /LD    /LD가 DLL로 만들라는 옵션
