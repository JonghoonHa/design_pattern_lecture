// 6_��������_3 - 39page
#include <iostream>
using namespace std;

// ���ø� ���ڷ� ��å Ŭ������ ��ü�ϴ� ���

// "Policy Base Design"
// �������� ������ ���� 23�������� ���� C++���� ���!! (��������_2 ���� �̰� �� ����)
// ��� ��å Ŭ������ ���Ѿ��ϴ� ��Ģ�� �ְԵ˴ϴ�.
// �Ʒ� ��å Ŭ������ lock/unlock�� �־�� �մϴ�.

// ����: ��å �ڵ尡 �ζ��� ġȯ�ȴ�. ��å ���濡 ���� �������ϰ� ����.
// ����: ���� �ð��� ��å ������ �Ұ����ϴ�. (������ ����ȭ ��å�� ���� �� ����� �ʿ� ����.)
//       ����ȭ ��å�� ������ �� ���� �ٸ� List �ڵ� ���� - �޸� ����

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

// ����ȭ ��å�� ���� ��å Ŭ����
class NoLock
{
public:
	inline void lock()   {} // ������ �ƹ� �ϵ� ���� �ʴ� inline�Լ��� compile����ȭ �߿� ��������.
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