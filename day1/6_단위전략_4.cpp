#include <iostream>
using namespace std;

// C++ ǥ�� ���̺귯���� STL�� �����غ��ô�.

template<typename T, typename Alloc =  allocator<T> > class vector
{
	T* buff;
	int sx;
	Alloc ax; // �޸� �Ҵ��(�������� ����)
public:
	void resize(int n) 
	{
		// �޸� �Ҵ��� �ʿ��մϴ�. ��� �ұ�?
		// malloc? new? realloc? brk()? windows api?
		buff = ax.allocate(n); // T�� n�� �Ҵ�

		ax.deallocate(buff, n); // �޸� ����
	}
};

int main()
{

}