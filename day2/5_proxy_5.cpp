// 5_proxy_5

#include <iostream>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

// ���� Ŭ���̾�Ʈ �����ڴ� ���� �����ڿ��� 2���� ������ �޾ƾ� �մϴ�.
// Icalc.h        : �������̽��� ��� ���
// Proxy.dll(.so) : proxy�� ��� ���� ���
#include "ICalc.h"

int main()
{
	// ���� ����� load�ϰ� ��⿡�� ��ӵ� �Լ� ã��
	void* addr = ec_load_module("proxy.dll"); //dl_open()

	typedef ICalc*(*F)();
	F f = (F)ec_get_function_address(addr, "CreateProxy");
	// ---------------------------------------------------

	ICalc* pCalc = f();

	cout << pCalc->Add(1, 2) << endl;
}
// proxy�� update�Ϸ���
// 1. ���� ����� �̸�(proxy.dll)�� �ݵ�� �����ؾ� �Ѵ�.
// 2. ���� ��� �ȿ��� "CreateProxy" �Լ��� �ݵ�� �־�� �Ѵ�.
