// 3_�߻�Ŭ����_3
#include <iostream>
using namespace std;

// ���� ���� (loosely coupling): �ϳ��� Ŭ������ �ٸ� Ŭ���� ��� �� Ŭ���� �̸��� �ٷ� ������� �ʰ�
//                               ��� Ŭ����(�߻�Ŭ����) �̸����� ��ü ������ ������ ������. OCP�� �����Ѵ�.

// ī�޶�� ī�޶� ����� ������ ��Ģ�� ���� ��������.
// ��Ģ: "��� ī�޶�� �Ʒ� Ŭ�����κ��� �Ļ��Ǿ�� �Ѵ�." ��� ǥ������ ����
//       "��� ī�޶�� �Ʒ� �������̽��� �����ؾ� �Ѵ�."��� ǥ��

// �������̽�: ��Ģ�� ���� �߻�Ŭ����
struct ICamera
{
	virtual void take() = 0;
	virtual ~ICamera() {}    // ��� ��� Ŭ������ �Ҹ��ڰ� �����̾�� �Ѵ�. C++ �⺻ ����.
};

// ��Ģ�� �����Ƿ� ��Ģ��� ���� �ȴ�.
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