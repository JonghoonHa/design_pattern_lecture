// 4_어답터_3
#include <iostream>
using namespace std;

// STL에는 이미 linked list가 있습니다.
#include <list>

// 그런데 스택이 필요합니다.
// 1. 새롭게 만들자
// 2, list의 함수 이름을 변경해서 stack처럼 보이게하자

// 상속: 구현 뿐 아니라 인터페이스도 물려받겠다는 의미
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
// 해결책 1. private(또는 protected) 상속. -> 여기서 구현된 함수를 제외한 나머지 기반 클래스의 멤버 함수는 사용하지 않겠다
// private 상속: 구현은 물려받지만 인터페이스는 물려받지 않겠다
template<typename T> class stack : private list<T>
{
public:
	inline void push(const T& a) { list<T>::push_back(a); }
	inline void pop() { list<T>::pop_back(); }
	inline T&   top() { return list<T>::back(); }
};
*/

// 해결책 2. 많은 경우 상속보다 포함이 좋다.
// 1번과 차이점: list<T>에 가상함수가 있다면 1번에서는 재정의 가능. 포함모델은 재정의 안됨.
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
	// s.push_front(30); // 잘못 사용했다!
}