// 1_singleton_3: 123 page
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
		mtx.lock(); // 여기서 deadlock 생길 위험이 있다. 멀티스레드에서 하나는 여기서 멈추고
		if (sinstance == nullptr)
			sinstance = new Cursor; // 생성자에서 오류 나면 예외처리하고 걍 나가버림
		mtx.unlock();

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