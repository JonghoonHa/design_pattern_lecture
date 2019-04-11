// 6_단위전략_2 - 37page

// 전략 패턴을 사용해서 동기화 코드는 분리해보자.

// 장점: 실행시간에 동기화 정책을 교체 할 수 있다.
// 단점: 가상함수 기반이다. 메모리 사용량 증가 (가상함수 테이블)
//       성능의 이슈 (가상함수를 가상함수 테이블을 사용해서 호출)

struct ISync
{
	virtual void Lock() = 0;
	virtual void UnLock() = 0;
	virtual ~ISync() {}
};
template<typename T> class List
{
public:
	void setSync(ISync* p) { pSync = p; }

	void push_front(const T& a)
	{
		// nullptr: 포인터 0을 의미. from C++11
		if (pSync != nullptr) pSync->Lock();
		//....
		if (pSync != nullptr) pSync->UnLock();
	}
};

List<int> s; // 전역변수 - 멀티스레드에 안전하지 않다.

int main()
{
	s.push_front(10);
}