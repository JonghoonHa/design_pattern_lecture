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
// 기반 클래스가 템플릿인데 파생 클래스가 자신의 이름을 템플린 인자를 통해서 기반클래스에게 전달하는 기술
// 미래에 만들어질 파생 클래스의 이름을 기반 클래스 만들 때 사용할 수 있다.
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

// 아래 클래스도 싱글톤으로 하고싶습니다.
class LedService : public Singleton<LedService>
{

};

int main()
{
	LedService& s1 = LedService::getInstance();
}