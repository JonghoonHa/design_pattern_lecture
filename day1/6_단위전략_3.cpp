// 6_단위전략_3 - 39page
#include <iostream>
using namespace std;

// 템플릿 인자로 정책 클래스를 교체하는 기술

// "Policy Base Design"
// 전통적인 디자인 패턴 23가지에는 없는 C++만의 기술!! (단위전략_2 보다 이게 더 좋다)
// 모든 정책 클래스는 지켜야하는 규칙이 있게됩니다.
// 아래 정책 클래스는 lock/unlock이 있어야 합니다.

// 장점: 정책 코드가 인라인 치환된다. 정책 변경에 따른 성능저하가 없다.
// 단점: 실행 시간에 정책 변경이 불가능하다. (하지만 동기화 정책은 실행 시 변경될 필요 없다.)
//       동기화 정책은 변경할 때 마다 다른 List 코드 생성 - 메모리 증가

template<typename T, typename SyncModel = NoLock> class List
{
	SyncModel sm;
public:
	void push_front(const T& a)
	{
		sm.lock();
		//....
		sm.unlock();
	}
};

// 동기화 정책을 담은 정책 클래스
class NoLock
{
public:
	inline void lock()   {} // 실제로 아무 일도 하지 않는 inline함수는 compile최적화 중에 지워진다.
	inline void unlock() {}
};
class PosixMutexLock
{
	// pthread_mutex_t pm;
public:
	inline void lock() { cout << "mutex lock" << endl; }
	inline void unlock() { cout << "mutex unlock" << endl; }
};

List<int, NoLock> s;
List<int, PosixMutexLock> s;

int main()
{
	s.push_front(10);
}