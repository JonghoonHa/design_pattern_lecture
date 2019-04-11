// user_define_literal
#include <iostream>
using namespace std;

class Weight
{
	int value;
public:
	Weight(int v) : value(v) {}
};

// user define literal ��Ģ
// ���� ���ͷ�: unsigned long long ���� ���
// ���ڿ� ���ͷ�: const char* ���� ���
// ����� �������� ù ���ڿ� ������ '_'�ٿ��� �Ѵ�. �⺻���� �浹�� �� ����
Weight operator""_gram(unsigned long long v)
{
	return Weight(v);
}

int main()
{
	float f = 3.4f;

	Weight w = 3_gram; // operator""gram(3)�� ȣ��˴ϴ�. ���� '��� + ����'�� ���տ����� ����!
}