// 2_container_6: 99 page
#include <iostream>
using namespace std;

// iterator: 컨테이너의 내부 구조에 상관없이 동일한 방법으로 모든 요소를 열거하는 객체를 만들자
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
	void push_front(T a) {} // 구현은 생략..!
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

	// 사용법
	// 1. 컨테이너에서 반복자를 꺼낸다
	slist_enumerator e1 = s.GetEnumerator();
	myvector_enumeraotr e2 = v.GetEnumerator();

	// 2. 반복자의 멤버 함수를 사용해서 요소에 접근/이동한다.
	int n = e1.Object(0); //요소 꺼내기. 즉, 30
	e1.MoveNext(0);       // 다음으로 이동
	int n2 = e1.Object(); // 20

	// e2도 사용법이 같아야 한다.

}