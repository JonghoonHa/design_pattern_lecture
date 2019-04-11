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
		// DLC�� ������: �����Ϸ� ����ȭ�� ���� reordering ����
		if (sinstance == nullptr)
		{
			mtx.lock();
			if (sinstance == nullptr)
				sinstance = new Cursor;
			// �� �� ���� �Ʒ�ó�� �����մϴ�.
			// 1. �޸� �Ҵ�: temp = �޸� �Ҵ� �Լ� (sizeof(Cursor))
			// 2. ������ ȣ��: Cursor::Cursor()
			// 3. �޸� �ּҸ� ������ �ֱ�: sinstance = temp;
			// �׷��� ����ȭ(temp ����)�� ���� 2���� 3���� ������ ����Ǵ� ��찡 �ִ�.
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