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
		mtx.lock(); // ���⼭ deadlock ���� ������ �ִ�. ��Ƽ�����忡�� �ϳ��� ���⼭ ���߰�
		if (sinstance == nullptr)
			sinstance = new Cursor; // �����ڿ��� ���� ���� ����ó���ϰ� �� ��������
		mtx.unlock();

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