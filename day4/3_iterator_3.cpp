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

	// 반복자를 꺼내는 함수의 이름을 인터페이스로 약속하지 말고
	// 문서화 하자.
	// begin을 사용하기로 하자.
	slist_iterator<T> begin() { return slist_iterator<T>(head); }
};


int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

	slist_iterator<int> p = s.begin();
	cout << *p << endl;
	++p;
	cout << *p << endl;
}

// 위에 IEnumerable 지우세요.



