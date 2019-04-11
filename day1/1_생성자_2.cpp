// 1_생성자_2.cpp

// protected 생성자: 자신의 객체를 생성할 수는 없지만
//                   파생 클래스의 객체는 만들 수 있게 하는 기법
//                   동물이라는 개념은 추상적인 개념으로 객체가 존재하지 않는다.

class Animal
{
protected:
	Animal() {}
};

class Dog : public Animal
{
public:
	Dog() {}
};

int main()
{
	// 다음 중 에러는?
	Animal a; // error
	Dog d; // ok
}