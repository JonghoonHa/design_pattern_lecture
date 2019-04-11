// 1_singleton_7
#include <iostream>
#include <mutex>
using namespace std;

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor& c) = delete;
	void operator=(const Cursor&) = delete;

	static Cursor* sinstance;
	static mutex   mtx;
public:
	static Cursor& getInstance()
	{
		// DLC의 문제점: 컴파일러 최적화에 의한 reordering 현상
		if (sinstance == nullptr)
		{
			mtx.lock();
			if (sinstance == nullptr)
				sinstance = new Cursor;
			// 위 한 줄은 아래처럼 동작합니다.
			// 1. 메모리 할당: temp = 메모리 할당 함수 (sizeof(Cursor))
			// 2. 생성자 호출: Cursor::Cursor()
			// 3. 메모리 주소를 변수에 넣기: sinstance = temp;
			// 그런데 최적화(temp 제거)를 위해 2번과 3번의 순서가 변경되는 경우가 있다.
			mtx.unlock();
		}

		return *sinstance;
	}
};
// static 멤버 변수는 외부 선언이 필요하다
Cursor* Cursor::sinstance = nullptr;
mutex   Cursor::mtx;

int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();
}