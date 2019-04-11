// 4_어답터_4
// 4_어답터_3
#include <iostream>
#include <list>
#include <vector>
#include <deque>
using namespace std;
/*
// 클래스 어답터이다. 내부에 C st가 정해져있으니까!
template<typename T, typename C= deque<T>> class stack
{
	C st;
public:
	inline void push(const T& a) { st.push_back(a); }
	inline void pop() { st.pop_back(); }
	inline T&   top() { return st.back(); }
};
*/

#include <stack> // C++ 표준의 스택.. 위의 작성 코드처럼 구현되어있다!
                 // 그래서 'stack adapter'라고 부른다.
int main()
{
	stack<int> s2;              // 기본으로 deque<int>를 사용하는 스택
	stack<int, list<int>> s;    // list를 스택으로 변경해달라
	stack<int, vector<int>> s1; // vector를 스택으로 변경해달라
	s.push(10);
	s.push(20);
}