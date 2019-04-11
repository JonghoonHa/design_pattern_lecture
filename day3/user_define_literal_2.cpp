// user_define_literal_2
#include <iostream>
#include <string>
#include <complex>
#include <chrono>  // 시간 관련 라이브러리
using namespace std;
using namespace std::chrono;

void foo(const char* s) { cout << "const char*" << endl; }
void foo(string s)      { cout << "string" << endl; }

int main()
{
	foo("hello"); // const char*
	foo("hello"s); // string
	complex<int> c1(3, 2); // 3 + 2i
	complex<int> c2(3);    // 3 + 0i
	complex<int> c3(3i);   // 0 + 3i
	complex<int> c4(-3i);  // 0 - 3i

	seconds s1 = 30s;
	milliseconds s2 = 1h + 3min + 24s;

	cout << s2.count() << endl;

	// minutes m1 = 1h + 3min + 24s; // error
	minutes m2 = duration_cast<minutes>(1h + 3min + 24s); // ok, 버림

	typedef duration<int, ratio<1, 1>> Meter;
	typedef duration<int, ratio<1, 100>> CentiMeter;

	Meter m3(300); // 300cm이 되려면 operator""cm()이 필요
	CentiMeter cm = m3; // 자동 계산됨
	cout << cm.count() << endl;
}
