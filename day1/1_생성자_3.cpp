// 1_������_3

// ��� Ŭ������ default�����ڰ� ������
// 1. �Ļ� Ŭ�������� ��� Ŭ������ �����ڸ� ���������
//    ȣ���ϴ� �ڵ带 �����ؾ� �Ѵ�
class Base
{
public:
	Base(int a){}
};

class Derived : public Base
{
public:
	/*
	Derived()  // : Base() �ϰ�; Base �� defualt�����ڰ� ��� ����. ���⼭ ��������� ���⸸ �ϸ� Base�� ��� ��
	{
	}
	*/
	Derived() : Base(0)  // �䷸��!
	{
	}
};

int main()
{
	Derived d; // �� �����ϱ��?
}