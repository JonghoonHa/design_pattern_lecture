// 3_�Լ�������_2
#include <iostream>

// 1. �Ϲ��Լ� �����Ϳ� ����Լ��� �ּҸ� ���� �� ����. this�� ���� ����
// 2. �Ϲ��Լ� �����Ϳ� static ����Լ��� �ּҸ� ���� �� ����.
// 3. ��� �Լ��� �ּҸ� ��� ������ ����� ���
// 4. ��� �Լ� �����͸� ����ؼ� �Լ��� ȣ���ϴ� ��� '.*'������! 32�� ����~

class Dialog
{
public:
	void close() {}
};
void foo() {}

int main()
{
	void(*f1)() = &foo; // ok
	// void(*f2)() = &Dialog::close; // error. this ���ڰ� �����־ ����� ������ ��!!

	void(Dialog::*f2)() = &Dialog::close; //ok
	printf("%p\n", f2);

	// f2(); // error. ��ü(this)�� �����ϴ�.

	Dialog dlg;
	// dlg.f2(); // error. f2�� ��� �Լ��� �ƴ� �Լ������ʹ�. f2��� ����� ����.

	// dlg.*f2(); // '.*' : pointer to member ��� C++�� �߰��� ������
	              // '.*' ���� ()�� �켱������ ����. error

	(dlg.*f2)(); // ok.. dlg.close()�� �ǹ̿� ����.
}