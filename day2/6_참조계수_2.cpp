#include <iostream>
using namespace std;

class Car
{
	int color;
	int mCount = 0; // 참조계수를 위한 멤버

public:
	~Car() { cout << "~Car" << endl; }

	void AddRef() { ++mCount; }
	void Release() { if (--mCount == 0) delete this; }
};

int main()
{
	Car* p1 = new Car;
	p1->AddRef(); // 규칙 1. 객체 생성 시에 참조계수 증가
	Car* p2 = p1;
	p2->AddRef(); // 규칙 2. 객체 포인터 복사 시 참조계수 증가

	p2->Release(); // 규칙 3. 포인터 사용 후 참조계수 감소
	p1->Release();
}