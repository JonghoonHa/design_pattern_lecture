// 1_singleton: 123 page
#include <iostream>
using namespace std;

// singleton: 오직 하나의 객체만 존재하고
//            시스템 어디에서도 동일한 방법으로 접근 가능한 객체

// mayer의 싱글톤: 오직 하나의 객체가 static 지역변수로 되어있는 경우
//                 effective C++ 시리즈의 저자가 처음 제안한 코드
class Cursor
{
	// 규칙 1. private 생성자
private:
	Cursor() {}
	// 규칙 2. 오직 한 개의 객체를 만들어 반환하는 static 멤버 함수
public:
	static Cursor& getInstance()
	{
		static Cursor instance;
		return instance;
	}
	// 규칙 3. 복사생성자와 대입연산자를 사용할 수 없게 한다.
	// 옛날 방법: private에 선언만 한다.
//private:
	// Cursor(const Cursor& c); // 구현부가 없어 Cursor 내부에서 사용하더라도 link error 나도록 유도함.
	// 새로나온 방법: C++11 부터 '함수 삭제'문법 사용
	Cursor(const Cursor& c) = delete;
	void operator=(const Cursor&) = delete;
};

int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	// Cursor c3 = c1; // 이 때는 복사생성자가 호출되는데, 호출 못하게 해야한다
	// Cursor c1;
	// Cursor c2;
}