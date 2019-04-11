// proxy_2
#include <iostream>
#include <atomic> // C++11���� �����ϴ� �����忡 ������ Ÿ��
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

	// ��������� �Լ�
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

extern "C" __declspec(dllexport)  // windows dll ���� �� �ʿ�
ICalc* CreateProxy()
{
	return new Calc;
}

// ���� �ϴ� ��: cl proxy.cpp /LD    /LD�� DLL�� ������ �ɼ�
