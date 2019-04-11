// 1_singleton_4
#include <iostream>
#include <mutex>
using namespace std;

// ������/�Ҹ��ڸ� ����ؼ� lock/unlock�� �ϴ� ���� �����ϴ�.
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
		lock_guard<mutex> g(mtx); // Autolockó�� ������� C++ǥ��Ŭ����
		                          // C++11���� ����
		// Autolock al(mtx);
		// mtx.lock();
		if (sinstance == nullptr)
			sinstance = new Cursor;
		//mtx.unlock();

		// 'al'�� ���������̱� ������ �� ���� �Ѿ �� �ڵ����� �Ҹ���(���� unlock) ȣ���Ѵ�
		// 'C++�� deadlock �߻� �ÿ��� ���������� �����ϰ� �ı��ȴ�'�� ��
		return *sinstance;

	}


};
// static ��� ������ �ܺ� ������ �ʿ��ϴ�
Cursor* Cursor::sinstance = nullptr;
mutex   Cursor::mtx;

int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();
}