// 3_함수포인터_5
#include <iostream>
using namespace std;

class Dialog
{
public:
	void close() { cout << "Dialog Close" << endl; }
};
void foo() { cout << "foo" << endl; }

// ---------------------------------------------------
// 함수포인터를 관리하는 클래스들의 기반 클래스
struct ICommand
{
	virtual void Execute() = 0;
	virtual ~ICommand() {}
};

// 일반 함수포인터를 관리하는 클래스
class FunctionCommand : public ICommand
{
	void(*handler)();
public:
	FunctionCommand(void(*f)()) : handler(f) {}
	virtual void Execute() { handler(); }
};

// 멤버 함수 포인터는 모든 클래스에 적용되어야 한다. template 사용
template<typename T> class MemberFunction : public ICommand
{
	void(T::*handler)(); // 함수 주소
	T* target;           // 객체
public:
	MemberFunction(void(T::*f)(), T* obj) : handler(f), target(obj) {}
	virtual void Execute()
	{
		// pointer to member : '.*', '->*'
		(target->*handler)();
	}
};

// 클래스 템플릿을 만드는 함수 템플릿
template<typename T> MemberFunction<T>* action(void(T::*f)(), T* obj)
{
	return new MemberFunction<T>(f, obj);
}
// 일반함수 버젼의 함수 템플릿
// FunctionCommand 도 action함수를 사용하자
FunctionCommand* action(void(*f)())
{
	return new FunctionCommand(f);
}

int main()
{
	Dialog dlg;
	ICommand* p1 = action(&Dialog::close, &dlg);
	ICommand* p2 = action(&foo);

	p1->Execute();
	p2->Execute();
}

/*
int main()
{
	Dialog dlg;
	ICommand* p2 = new MemberFunction<Dialog>(&Dialog::close, &dlg);
	p2->Execute(); // dlg.Close()

	ICommand* p = new FunctionCommand(&foo);
	p->Execute(); // foo() 실행. 결국 함수포인터처럼 함수 보관했다가 실행
}
*/