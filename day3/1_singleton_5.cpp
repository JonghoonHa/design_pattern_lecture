// 1_singleton_5
#include <iostream>
#include <mutex>
using namespace std;

class Autolock
{
	mutex& mtx;
public:
	Autolock(mutex& m) : mtx(m) { mtx.lock(); }
	~Autolock() { mtx.unlock(); }
};

// CRTP: Curiously Recurring Template Pattern
// ��� Ŭ������ ���ø��ε� �Ļ� Ŭ������ �ڽ��� �̸��� ���ø� ���ڸ� ���ؼ� ���Ŭ�������� �����ϴ� ���
// �̷��� ������� �Ļ� Ŭ������ �̸��� ��� Ŭ���� ���� �� ����� �� �ִ�.
template<typename TYPE> class Singleton
{
protected:
	Singleton() {}
private:
	Singleton(const Singleton& c) = delete;
	void operator=(const Singleton&) = delete;

	static TYPE* sinstance;
	static mutex   mtx;
public:
	static TYPE& getInstance()
	{
		Autolock al(mtx);

		if (sinstance == nullptr)
			sinstance = new TYPE;

		return *sinstance;

	}
};
template<typename TYPE>TYPE* Singleton<TYPE>::sinstance = nullptr;
template<typename TYPE>mutex Singleton<TYPE>::mtx;

// �Ʒ� Ŭ������ �̱������� �ϰ�ͽ��ϴ�.
class LedService : public Singleton<LedService>
{

};

int main()
{
	LedService& s1 = LedService::getInstance();
}