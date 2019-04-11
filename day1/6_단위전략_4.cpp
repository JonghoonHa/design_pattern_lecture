#include <iostream>
using namespace std;

// C++ 표준 라이브러리인 STL을 생각해봅시다.

template<typename T, typename Alloc =  allocator<T> > class vector
{
	T* buff;
	int sx;
	Alloc ax; // 메모리 할당기(단위전략 패턴)
public:
	void resize(int n) 
	{
		// 메모리 할당이 필요합니다. 어떻게 할까?
		// malloc? new? realloc? brk()? windows api?
		buff = ax.allocate(n); // T를 n개 할당

		ax.deallocate(buff, n); // 메모리 해지
	}
};

int main()
{

}