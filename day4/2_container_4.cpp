// 2_container_4: 99 page
#include <iostream>
using namespace std;

// 방법 3. thin template
// 구글에서 'C++ Idioms' 검색하면 첫 번째 링크
// Architecture: 언어 설계, OS 설계, 규모가 큰 시스템 설계 방법
// Design Pattern: 중간 규모의 객체지향 코딩 방법. 언어에 독립적인 코딩 방법
// Idioms: 소규모의 특정 언어만의 코딩 방법
struct Node
{
    void*   data;
	Node* next;
	Node(void* d, Node* n) : data(d), next(n) { }
};

class slistimp
{
	Node* head = 0;
public:
	void push_front(void* n) { head = new Node(n, head); }
	void* front() { return head->data; }
};
// slistimp를 직접 사용하면 항상 캐스팅을 해야한다... 너무 불편해!
// 캐스팅만 책임지는 클래스 템플릿을 만들자
template <typename T> class slist : public slistimp
{
public:
	inline void push_front(T a) { slistimp::push_front((void*)a); }
	T front() { return (T)slistimp::front(); }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	int n = s.front();
}