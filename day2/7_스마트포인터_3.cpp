// 7_스마트포인터_3
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

template<typename T>class Ptr
{
	T* obj;
public:
	Ptr(T* p = 0) : obj(p) 
	{ 
		if (obj != nullptr)
			obj->AddRef();
	}

	// 복사 생성자
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
	Ptr<Car> p1 = new Car; // 안드로이드 프레임워크 :sp<Car> p = new Car;
	Ptr<Car> p2 = p1;
}