// 3_�Լ�������_4

// Ŭ�������ø� vs �Լ� ���ø�

template<typename T> int square(T a)
{
	return a * a;
}

template<typename T> class List
{
public:
	List(int sz, T value) {}
};
// �Լ� ���ø�: Ÿ���� ������� �ʾƵ� �Լ����ڷ� �߷� ����
// Ŭ���� ���ø�: �ݵ�� Ÿ���� ����ؾ� �Ѵ�.

// Ŭ���� ���ø��� ���� ����ϸ� �����غ��δ�.
// Ŭ���� ���ø��� ����� �Լ����ø��� �������� - "Object Generator"

template<typename T> List<T> makeList(int sz, T value)
{
	return new List<T>(sz, value);
}

int main()
{
	square<int>(3);
	square(3); // 3�� ������ T�� Ÿ���� �߷��Ѵ�.

	// List<int> s1(10, 0);
	// List s1(10, 0);
	makeList(10, 0);
}