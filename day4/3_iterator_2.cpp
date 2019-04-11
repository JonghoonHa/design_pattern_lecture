#include <iostream>
using namespace std;

template<typename T> struct Node
{
	T   data;
	Node* next;
	Node(T d, Node* n) : data(d), next(n) { }
};

// iterator : 컨테이너의 요소를 차례대로 열거할때 사용하는 객체
// 모든 컨테이너의 iterator는 사용법이 동일해야한다.
// iterator의 인터페이스
// C# 1.0 시절 - object 기반 컨테이너
/*
struct IEnumerator
{
	virtual bool MoveNext() = 0; // 다음으로 이동
	virtual object* Object() =  0;     // 값 꺼내기
	virtual ~IEnumerator() = 0; 
};
*/
// C#2.0, 삼성타이젠(C++).. 템플릿 기반 인터페이스
template<typename T> struct IEnumerator
{
	virtual bool MoveNext() = 0; // 다음으로 이동
	virtual T Object() = 0;     // 값 꺼내기
	virtual ~IEnumerator() {};
};

// 모든 컨테이너는 반복자를 꺼낼수 있어야 한다.
// 컨테이너의 인터페이스
template<typename T> struct IEnumerable
{
	virtual IEnumerator<T>* GetEnumerator() = 0;
	virtual ~IEnumerable() {}
};

// slist의 반복자
template<typename T> 
struct slist_enumerator : public IEnumerator<T>
{
	Node<T>* current = 0;
public:
	slist_enumerator(Node<T>* p = 0) : current(p) {}

	virtual bool MoveNext()
	{
		current = current->next;
		return current;
	}
	virtual T Object()
	{
		return current->data;
	}
};




// 모든 컨테이너는 반복자를 꺼낼수 있어야 한다.

template<typename T> class slist : public IEnumerable<T>
{
	Node<T>* head = 0;
public:
	void push_front(T n) { head = new Node<T>(n, head); }

	T front() { return head->data; }

	virtual IEnumerator<T>* GetEnumerator()
	{
		return new slist_enumerator<T>(head);
	}
};


int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

	IEnumerator<int>* p = s.GetEnumerator();

	cout << p->Object() << endl;
	p->MoveNext();

	cout << p->Object() << endl;
}




