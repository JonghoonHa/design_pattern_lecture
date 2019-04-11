#include <iostream>
using namespace std;

template<typename T> struct Node
{
	T   data;
	Node* next;
	Node(T d, Node* n) : data(d), next(n) { }
};

template<typename T> struct slist_iterator
{
	Node<T>* current = 0;
public:
	slist_iterator(Node<T>* p = 0) : current(p) {}

	inline slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}
	inline T& operator*()
	{
		return current->data;
	}
};

template<typename T> class slist
{
	Node<T>* head = 0;
public:
	void push_front(T n) { head = new Node<T>(n, head); }

	T front() { return head->data; }

	// ��� �����̳ʴ� �ڽ��� �ݺ��� �̸��� ��ӵ� ���·� �ܺο� �˸���� ����.
	typedef slist_iterator<T> iterator;

	iterator begin() { return slist_iterator<T>(head); }
};


int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

	// slist_iterator<int> p = s.begin();
	slist<int>::iterator p = s.begin();

	cout << *p << endl;
	++p;
	cout << *p << endl;
}



