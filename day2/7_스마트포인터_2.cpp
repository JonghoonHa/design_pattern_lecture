// 7_����Ʈ������_2
#include <iostream>
#include <memory>
using namespace std;

template<typename T>class Ptr
{
	T* obj;
public:
	Ptr(T* p = 0) : obj(p) {}
	T* operator->() { return obj; }
	T& operator*() { return *obj; }

	~Ptr() { delete obj; }
};

int main()
{
	Ptr<int> p1 = new int;
	*p1 = 10;
	cout << *p1 << endl;

	// ����ڰ� ������ �ʾƵ� C++ ǥ�뿡 �̹� �ִ�.
	shared_ptr<int> sp(new int);
	*sp = 10;
}