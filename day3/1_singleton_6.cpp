// 1_singleton_6
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
		// 2번의 if문
		// 단점: 최초 호출 시 2번의 if문을 실행하게된다.
		// 장점: 객체가 생성된 후에 이 함수를 호출하면 lock/unlock이 실행될 필요가 없다.
		// DLCP: Double Check Locking Pattern
		if (sinstance == nullptr)
		{
			mtx.lock();
			if (sinstance == nullptr)
				sinstance = new Cursor;
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