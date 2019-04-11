// 6_단위전략_1 - 37page

template<typename T> class List
{
public:
	void push_front(const T& a)
	{
		//....
	}
};

List<int> s; // 전역변수 - 멀티스레드에 안전하지 않다.

int main()
{
	s.push_front(10);
}