// 3_�Լ�������_3
#include <iostream>
using namespace std;

class Dialog
{
public:
	void close() { cout << "Dialog Close" << endl; }
};
void foo() { cout << "foo" << endl; }

// ---------------------------------------------------
// �Լ������͸� �����ϴ� Ŭ�������� ��� Ŭ����
struct ICommand
{
	virtual void Execute() = 0;
	virtual ~ICommand() {}
};

// �Ϲ� �Լ������͸� �����ϴ� Ŭ����
class FunctionCommand : public ICommand
{
	void(*handler)();
public:
	FunctionCommand( void(*f)() ) : handler(f) {}
	virtual void Execute() { handler(); }
};

// ��� �Լ� �����ʹ� ��� Ŭ������ ����Ǿ�� �Ѵ�. template ���
template<typename T> class MemberFunction : public ICommand
{
	void(T::*handler)(); // �Լ� �ּ�
	T* target;           // ��ü
public:
	MemberFunction(void(T::*f)(), T* obj) : handler(f), target(obj) {}
	virtual void Execute()
	{
		// pointer to member : '.*', '->*'
		(target->*handler)();
	}
};
int main()
{
	Dialog dlg;
	ICommand* p2 = new MemberFunction<Dialog>(&Dialog::close, &dlg);
	p2->Execute(); // dlg.Close()

	ICommand* p = new FunctionCommand(&foo);
	p->Execute(); // foo() ����. �ᱹ �Լ�������ó�� �Լ� �����ߴٰ� ����
}