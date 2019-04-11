// 4_�����_3
#include <iostream>
using namespace std;

// STL���� �̹� linked list�� �ֽ��ϴ�.
#include <list>

// �׷��� ������ �ʿ��մϴ�.
// 1. ���Ӱ� ������
// 2, list�� �Լ� �̸��� �����ؼ� stackó�� ���̰�����

// ���: ���� �� �ƴ϶� �������̽��� �����ްڴٴ� �ǹ�
/*
template<typename T> class stack : public list<T>
{
public:
	inline void push(const T& a) { list<T>::push_back(a); }
	inline void pop()            { list<T>::pop_back(); }
	inline T&   top()            { return list<T>::back(); }
};
*/

/*
// �ذ�å 1. private(�Ǵ� protected) ���. -> ���⼭ ������ �Լ��� ������ ������ ��� Ŭ������ ��� �Լ��� ������� �ʰڴ�
// private ���: ������ ���������� �������̽��� �������� �ʰڴ�
template<typename T> class stack : private list<T>
{
public:
	inline void push(const T& a) { list<T>::push_back(a); }
	inline void pop() { list<T>::pop_back(); }
	inline T&   top() { return list<T>::back(); }
};
*/

// �ذ�å 2. ���� ��� ��Ӻ��� ������ ����.
// 1���� ������: list<T>�� �����Լ��� �ִٸ� 1�������� ������ ����. ���Ը��� ������ �ȵ�.
template<typename T> class stack
{
	list<T> st;
public:
	inline void push(const T& a) { st.push_back(a); }
	inline void pop() { st.pop_back(); }
	inline T&   top() { return st.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	// s.push_front(30); // �߸� ����ߴ�!
}