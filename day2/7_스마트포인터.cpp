// 7_스마트포인터
#include <iostream>
using namespace std;

class Car
{
public:
	~Car() { cout << "~Car" << endl; }
	void Go() { cout << "Car Go" << endl; }

};

// 스마트 포인터
// 개념: 임의의 객체가 다른 타입의 포인터 역할을 하는 것
// 원리: -> 와 * 연산자를 재정의해서 포인터처럼 보이게 하는 것
// 장점: raw pointer가 아닌 객체이다.
//       생성, 복사, 대입, 소멸의 모든 과정에 추가의 기능을 수행할 수 있다.
//       대표적인 예가 소멸자에서 자원 삭제
// 아래가 핵심
class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = 0) : obj(p) {}
	Car* operator->() { return obj; }
	// Car operator*() { return *obj; } // 주의. 함수가 값 타입을 반환하면 복사본이 생성되어서 반환합니다.
	Car& operator*() { return *obj; }

	~Ptr() { delete obj; }
};

int main()
{
	Ptr p = new Car; // Ptr p(new Car)
	p->Go(); // (p.operator->())Go() 모양이지만
	         // (p.operator->())->Go()로 해석됩니다. C++의 특징
	(*p).Go();
}