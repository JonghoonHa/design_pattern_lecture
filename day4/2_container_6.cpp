// 2_container_6: 99 page
#include <iostream>
using namespace std;

// iterator: �����̳��� ���� ������ ������� ������ ������� ��� ��Ҹ� �����ϴ� ��ü�� ������
template<typename T>struct Node
{
	T   data;
	Node* next;
	Node(T&& T d, Node* n) : data(std::forward<T>(d)), next(n) { }
};
template<typename T>class slist
{
	Node<T>* head = 0;
public:
	void push_front(T&& n) { head = new Node<T>(std::forward<T>(n), head); }
	T& front() { return head->data; }
};

template<typename T> class myvector
{
	T* buff;
public:
	void push_front(T a) {} // ������ ����..!
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	
	myvector<int> v;
	v.push_front(10);
	v.push_front(20);

	// ����
	// 1. �����̳ʿ��� �ݺ��ڸ� ������
	slist_enumerator e1 = s.GetEnumerator();
	myvector_enumeraotr e2 = v.GetEnumerator();

	// 2. �ݺ����� ��� �Լ��� ����ؼ� ��ҿ� ����/�̵��Ѵ�.
	int n = e1.Object(0); //��� ������. ��, 30
	e1.MoveNext(0);       // �������� �̵�
	int n2 = e1.Object(); // 20

	// e2�� ������ ���ƾ� �Ѵ�.

}