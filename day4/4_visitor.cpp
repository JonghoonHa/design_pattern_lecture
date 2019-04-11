// 4_visitor
#include <iostream>
using namespace std;

template<typename T>struct Node
{
	T   data;
	Node* next;
	Node(T d, Node* n) : data(d), next(n) { }
};

template<typename T>class slist
{
	Node<T>* head = 0;
public:
	void push_front(T n) { head = new Node<T>(n, head); }
	T front() { return head->data; }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

	// �����̳��� ��� ��Ҹ� 2��� �����ϰ�ʹ�.
	// 1. ��� ��Ҹ� ������ 2��� �ؼ� �ٽ� �ִ´�.
	// 2. s.twiceAll() �̶�� ��� �Լ��� �����.
	// 3. �湮�� ������ ����Ѵ�

	TwiceVisitor tv; // ��� ��Ҹ� 2��� �ϴ� �湮�� (visitor)
	s.accept(&tv);
}