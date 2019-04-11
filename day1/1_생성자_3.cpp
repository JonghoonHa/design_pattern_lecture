// 1_생성자_3

// 기반 클래스에 default생성자가 없으면
// 1. 파생 클래스에서 기반 클래스의 생성자를 명시적으로
//    호출하는 코드를 제공해야 한다
class Base
{
public:
	Base(int a){}
};

class Derived : public Base
{
public:
	/*
	Derived()  // : Base() 하고싶어도 Base 에 defualt생성자가 없어서 오류. 여기서 명시적으로 쓰기만 하면 Base에 없어도 됨
	{
	}
	*/
	Derived() : Base(0)  // 요렇게!
	{
	}
};

int main()
{
	Derived d; // 왜 에러일까요?
}