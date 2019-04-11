// 7_����Ʈ������_3
#include <iostream>
using namespace std;

class Car
{
	int color;
	int mCount = 0; // ��������� ���� ���

public:
	~Car() { cout << "~Car" << endl; }

	void AddRef() { ++mCount; }
	void Release() { if (--mCount == 0) delete this; }
};

template<typename T>class Ptr
{
	T* obj;
public:
	Ptr(T* p = 0) : obj(p) 
	{ 
		if (obj != nullptr)
			obj->AddRef();
	}

	// ���� ������
	Ptr(const Ptr& ptr) : obj(ptr.obj)
	{
		if (obj != nullptr)
			obj->AddRef();
	}
	T* operator->() { return obj; }
	T& operator*() { return *obj; }
	~Ptr() 
	{
		if (obj != nullptr)
			obj->Release();
	}
};

int main()
{
	Ptr<Car> p1 = new Car; // �ȵ���̵� �����ӿ�ũ :sp<Car> p = new Car;
	Ptr<Car> p2 = p1;
}