// 2_container_3: 99 page
#include <iostream>
using namespace std;

// ��� 2. template
// ����: 1. Ÿ�� �������� �پ��, User Type�Ӹ��ƴ϶� primitive type�� �����ϴ�
//       2. ���� �� ĳ������ �ʿ� ����.
// ����: ���ø��̹Ƿ� �پ��� Ÿ������ ����ϸ� �ڵ�޸� ����
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
}