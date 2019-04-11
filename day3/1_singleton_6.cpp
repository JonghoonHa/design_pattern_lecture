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
		// 2���� if��
		// ����: ���� ȣ�� �� 2���� if���� �����ϰԵȴ�.
		// ����: ��ü�� ������ �Ŀ� �� �Լ��� ȣ���ϸ� lock/unlock�� ����� �ʿ䰡 ����.
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
// static ��� ������ �ܺ� ������ �ʿ��ϴ�
Cursor* Cursor::sinstance = nullptr;
mutex   Cursor::mtx;

int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();
}