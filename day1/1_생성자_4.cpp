#include <iostream>
using namespace std;

// 생성자 호출 순서 - 사용자가 순서를 변경할 수 없음
// 1. 기반 클래스의 멤버의 생성자
// 2. 기반 클래스의 생성자
// 3. 자신의 멤버의 생성자
// 4. 자신의 생성자

struct BM { BM() { cout << "BM()" << endl; } };
struct DM { DM() { cout << "DM()" << endl; } };

struct Base
{
	BM bm;
	Base() { cout << "BM()" << endl; }
};

struct Derived : public Base
{
	DM dm;
	Derived() { cout << "DM()" << endl; }
};

int main()
{
	Derived d;
}