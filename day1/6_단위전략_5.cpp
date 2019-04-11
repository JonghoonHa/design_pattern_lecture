#include <iostream>
#include <vector>
using namespace std;

// STL 컨테이너에 전달한 메모리 할당 정책을 담은 정책 클래스
template<typename T> class MyAlloc
{
public:
	// 사용자 정의 allocator에는 반드시 아래의 함수들이 있어야 합니다.
	typedef T value_type;

	MyAlloc() {} // 디폴트 생성자
	template<typename U> MyAlloc(const U& a) {} // 템플릿 생성자

	T* allocate(int n)
	{
		cout << n << "개 메모리 할당" << endl;

		T* p = static_cast<T*>(malloc(sizeof(T)*n));
		return p;
	}
	void deallocate(T* p, int n)
	{
		cout << "메모리 해지" << endl;
		free(p);
	}
};

int main()
{
	vector<int, MyAlloc<int> > v;

	v.resize(5);
}