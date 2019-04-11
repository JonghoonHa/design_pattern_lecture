// 2_upcasting

class Animal
{
public:
	int age;
};

class Dog : public Animal
{
public:
	int color;
};

int main()
{
	Dog d;
	Dog*    p1 = &d; // ok
	Animal* p2 = &d; // 기반클래스의 포인터(참조)에 파생 클래스의 주소를 담을 수 있다... upcasting
	
	p2->age = 10;           // ok
	p2->color = 10;         // error. 기반 클래스의 포인터로 사용 시 파생 클래스 고유 멤버는 접근 안됨
	((Dog*)p2)->color = 10; //ok. 파생 클래스로 캐스팅 해주면 괜찮다

	// 장점
	vector<Dog*> v1; // Dog 만 보관
	vector<Animal*> v2; // 모든 동물(Animal 파생클래스) 보관
}