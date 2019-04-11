// 3_추상클래스_3
#include <iostream>
using namespace std;

// 약한 결합 (loosely coupling): 하나의 클래스가 다른 클래스 사용 시 클래스 이름을 바로 사용하지 않고
//                               기반 클래스(추상클래스) 이름으로 교체 가능한 유연한 디자인. OCP를 만족한다.

// 카메라와 카메라 사용자 사이의 규칙을 먼저 설계하자.
// 규칙: "모든 카메라는 아래 클래스로부터 파생되어야 한다." 라고 표현하지 말고
//       "모든 카메라는 아래 인터페이스를 구현해야 한다."라고 표현

// 인터페이스: 규칙을 담은 추상클래스
struct ICamera
{
	virtual void take() = 0;
	virtual ~ICamera() {}    // 모든 기반 클래스는 소멸자가 가상이어야 한다. C++ 기본 문법.
};

// 규칙이 있으므로 규칙대로 쓰면 된다.
class People
{
public:
	void useCamera(ICamera* p) { p->take(); }
};

class Camera : public ICamera
{
public:
	void take() { cout << "take picture with camera" << endl; }
};
class HDCamera : public ICamera
{
public:
	void take() { cout << "take picture with HDcamera" << endl; }
};


int main()
{
	People p;
	Camera c;
	p.useCamera(&c);

	HDCamera hc;
	p.useCamera(&hc);
}