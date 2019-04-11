// cache
#include <iostream>
#include <Windows.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

// false sharing 문제 - 인터넷 검색ㄱㄱ

int value1 = 0;
int x[16]; // 캐쉬를 고려한 경계선
int value2 = 0;

DWORD __stdcall foo(void* p)
{
	// 스레드에서 전역변수를 바로 사용하지 말고, 전역변수의 내용을 지역변수로 옮겨서 작업
	int v1 = value1;

	for (int i = 0; i < 1000; i++)
		value1 = i;

	// 지역변수를 다시 전역변수로
	value1 = v1;
	return 0;
}
DWORD __stdcall goo(void* p)
{
	for (int i = 0; i < 1000; i++)
		value2 = i;
	return 0;
}

int main()
{
	CreateThread(0, 0, foo, 0, 0, 0);
	CreateThread(0, 0, goo, 0, 0, 0);
	getchar(); // 종료 방지
}
