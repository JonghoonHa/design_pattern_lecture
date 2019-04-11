// 3_추상클래스_2
#include <iostream>
using namespace std;

// OCP (Open close principle): 기능 호가장에 열려있고(Open, 클래스, 모듈이 추가되어도)
//                             코드 수정에는 닫혀야(Close, 기존 코드는 수정되면 안된다)
//                             는 원칙(Principle). 13 page

// SOLID: SRP, OCP, LSP, ISP, DIP

// 강한 결합 (tighty coupling): 하나의 클래스가 다른 클래스 사용 시 클래스 이름을 바로 사용하는 것.
//                              교체 불가능한 경직된 디자인. OCP를 만족할 수 없다.

class Camera
{
public:
	void take() { cout << "take picture with camera" << endl; }
};
class HDCamera
{
public:
	void take() { cout << "take picture with HDcamera" << endl; }
};
class People
{
public:
	void useCamera(Camera* p) { p -> take(); }
	void useCamera(HDCamera* p) { p->take(); }
};

int main()
{
	People p;
	Camera c;
	p.useCamera(&c);

	HDCamera hc;
	p.useCamera(&hc);
}