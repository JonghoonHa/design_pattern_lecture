// proxy_2
#include <iostream>
#include <atomic> // C++11에서 지원하는 스레드에 안전한 타입
#include "ecourse.hpp"
#include "ICalc.h"
using namespace std;
using namespace ecourse;

class Calc : public ICalc

{
	int server;
	atomic<int> mCount;
public:
	Calc() 
	{ 
		mCount.store(0);
		server = ec_find_server("Calc"); 
	}

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }

	// 참조계수용 함수
	void AddRef() { ++mCount;  }
	void Release() 
	{ 
		mCount.fetch_sub(1);
		int n = mCount.load();
		if (n == 0)
			delete this;
	}

	~Calc() { cout << "~Calc" << endl; }
};

extern "C" __declspec(dllexport)  // windows dll 만들 때 필요
ICalc* CreateProxy()
{
	return new Calc;
}

// 빌드 하는 법: cl proxy.cpp /LD    /LD가 DLL로 만들라는 옵션
