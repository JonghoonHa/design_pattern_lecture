// 3_함수포인터_1
// 핵심 1. 멤버함수는 인자로 this가 추가됩니다.
//      2. static 멤버 함수는 인자로 this가 추가되지 않는다.
class Point
{
	int x, y;
public:
	void set(int a, int b) // void set(Point* this, int a, int b)
	{
		x = a;             // this->x = a;
		y = b;             // this->y = b; 으로 컴파일된다.
	}
	static void foo(int a) // void foo(int a) // this가 없다. 멤버데이터에 접근이 불가능하다. 캬... python하고 똑같네
	{
		x = a; // this->x 가 되어야 하는데 this가 없다.
		       // 그래서 static 멤버 함수는 멤버 데이터에 접근 안된다.
	}
};

int main()
{
	Point::foo(10); // 객체 없이 호출 가능

	Point p1, p2;
	p1.set(10, 20); // 원리를 생각해보자
	                // set(&p1, 10, 20)
	                // push 20
	                // push 10
	                // mov ecx, &p1 // 객체주소는 대부분 레지스터로!
	                // call Point::set
}