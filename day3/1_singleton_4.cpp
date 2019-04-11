// 1_singleton_4
#include <iostream>
#include <mutex>
using namespace std;

// 생성자/소멸자를 사용해서 lock/unlock을 하는 것이 안전하다.
class Autolock
{
	mutex& mtx;
public:
	Autolock(mutex& m) : mtx(m) { mtx.lock(); }
	~Autolock() { mtx.unlock(); }
};

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
		lock_guard<mutex> g(mtx); // Autolock처럼 만들어진 C++표준클래스
		                          // C++11부터 지원
		// Autolock al(mtx);
		// mtx.lock();
		if (sinstance == nullptr)
			sinstance = new Cursor;
		//mtx.unlock();

		// 'al'은 지역변수이기 때문에 이 구간 넘어갈 때 자동으로 소멸자(안의 unlock) 호출한다
		// 'C++은 deadlock 발생 시에도 지역변수는 안전하게 파괴된다'고 함
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