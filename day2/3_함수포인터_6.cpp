// 3_�Լ�������_6
#include <iostream>
#include <functional>
using namespace std;

class Dialog
{
public:
	void close() { cout << "Dialog Close" << endl; }
};
void foo() { cout << "foo" << endl; }

// C++11���� �����ϴ� �Ϲ�ȭ�� �Լ� ������ function
int main()
{
	function<void()> f; // �Լ��� �ּҸ� ��Ҵٰ� ȣ���� �� ���

	f = &foo;
	f(); // �ᱹ foo()

	Dialog dlg;
	f = bind(&Dialog::close, &dlg); // '3_�Լ�������_5'���� ���� aciton�� ����� ���
	f();
}