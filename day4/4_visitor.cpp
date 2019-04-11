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

	// 컨테이너의 모든 요소를 2배로 증가하고싶다.
	// 1. 모든 요소를 꺼내서 2배로 해서 다시 넣는다.
	// 2. s.twiceAll() 이라는 멤버 함수를 만든다.
	// 3. 방문자 패턴을 사용한다

	TwiceVisitor tv; // 모든 요소를 2배로 하는 방문자 (visitor)
	s.accept(&tv);
}