// 2_container_3: 99 page
#include <iostream>
using namespace std;

// 방법 2. template
// 장점: 1. 타입 안정성이 뛰어나고, User Type뿐만아니라 primitive type도 가능하다
//       2. 꺼낼 때 캐스팅이 필요 없다.
// 단점: 템플릿이므로 다양한 타입으로 사용하면 코드메모리 증가
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