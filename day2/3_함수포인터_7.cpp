// 3_�Լ�������_7

#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders; // _1, _2, ... ���� 20������ ����

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}
int main()
{
	// bind() : N�� �Լ�(�Լ� ��ü)�� M������ �����ϴ� ����
	foo(1, 2, 3, 4); 
	bind(&foo, 5, 6, 7, 8)(); // 4�� -> 0��
	bind(&foo, 5, _1, 7, _2)(3, 8); // 4�� -> 2��

	bind(&foo, _3, _1, _2, 5)(7, 9, 3); // 3, 7, 9, 5 ������ ����
	                                     // 4�� -> 3�� �Լ���
}