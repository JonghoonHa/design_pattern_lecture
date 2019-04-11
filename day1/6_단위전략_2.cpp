// 6_��������_2 - 37page

// ���� ������ ����ؼ� ����ȭ �ڵ�� �и��غ���.

// ����: ����ð��� ����ȭ ��å�� ��ü �� �� �ִ�.
// ����: �����Լ� ����̴�. �޸� ��뷮 ���� (�����Լ� ���̺�)
//       ������ �̽� (�����Լ��� �����Լ� ���̺��� ����ؼ� ȣ��)

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
		// nullptr: ������ 0�� �ǹ�. from C++11
		if (pSync != nullptr) pSync->Lock();
		//....
		if (pSync != nullptr) pSync->UnLock();
	}
};

List<int> s; // �������� - ��Ƽ�����忡 �������� �ʴ�.

int main()
{
	s.push_front(10);
}