// 3_함수포인터_3
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
	FunctionCommand( void(*f)() ) : handler(f) {}
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
int main()
{
	Dialog dlg;
	ICommand* p2 = new MemberFunction<Dialog>(&Dialog::close, &dlg);
	p2->Execute(); // dlg.Close()

	ICommand* p = new FunctionCommand(&foo);
	p->Execute(); // foo() 실행. 결국 함수포인터처럼 함수 보관했다가 실행
}