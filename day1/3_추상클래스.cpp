// 3_추상클래스 10 page

// 추상 클래스 (abstract class): 순수 가상함수가 한 개 이상인 클래스
// 특징: 객체를 만들 수 없다.
// 의도: 특정 함수를 반드시 만들라고 지시하는 것.
class Shape
{
public:
	virtual void Draw() = 0; // 순수 가상함수 (pure virtual function)
};

class Rect : public Shape // 기반 클래스에서 물려 받은 순수 가상함수의 구현부를 제공하지 않으면 역시 추상클래스
{
public:
};                        // 구체화 (concrete) 클래스가 되려면 Draw() 구현부를 제공해야 한다.

int main()
{
	Shape s; // error. 추상 클래스는 객체를 만들 수 없다.
	Rect  r;
}