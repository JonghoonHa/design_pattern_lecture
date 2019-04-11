#include <iostream>
#include <vector>
using namespace std;

// STL �����̳ʿ� ������ �޸� �Ҵ� ��å�� ���� ��å Ŭ����
template<typename T> class MyAlloc
{
public:
	// ����� ���� allocator���� �ݵ�� �Ʒ��� �Լ����� �־�� �մϴ�.
	typedef T value_type;

	MyAlloc() {} // ����Ʈ ������
	template<typename U> MyAlloc(const U& a) {} // ���ø� ������

	T* allocate(int n)
	{
		cout << n << "�� �޸� �Ҵ�" << endl;

		T* p = static_cast<T*>(malloc(sizeof(T)*n));
		return p;
	}
	void deallocate(T* p, int n)
	{
		cout << "�޸� ����" << endl;
		free(p);
	}
};

int main()
{
	vector<int, MyAlloc<int> > v;

	v.resize(5);
}