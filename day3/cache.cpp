// cache
#include <iostream>
#include <Windows.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

// false sharing ���� - ���ͳ� �˻�����

int value1 = 0;
int x[16]; // ĳ���� ����� ��輱
int value2 = 0;

DWORD __stdcall foo(void* p)
{
	// �����忡�� ���������� �ٷ� ������� ����, ���������� ������ ���������� �Űܼ� �۾�
	int v1 = value1;

	for (int i = 0; i < 1000; i++)
		value1 = i;

	// ���������� �ٽ� ����������
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
	getchar(); // ���� ����
}
