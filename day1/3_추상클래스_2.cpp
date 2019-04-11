// 3_�߻�Ŭ����_2
#include <iostream>
using namespace std;

// OCP (Open close principle): ��� ȣ���忡 �����ְ�(Open, Ŭ����, ����� �߰��Ǿ)
//                             �ڵ� �������� ������(Close, ���� �ڵ�� �����Ǹ� �ȵȴ�)
//                             �� ��Ģ(Principle). 13 page

// SOLID: SRP, OCP, LSP, ISP, DIP

// ���� ���� (tighty coupling): �ϳ��� Ŭ������ �ٸ� Ŭ���� ��� �� Ŭ���� �̸��� �ٷ� ����ϴ� ��.
//                              ��ü �Ұ����� ������ ������. OCP�� ������ �� ����.

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