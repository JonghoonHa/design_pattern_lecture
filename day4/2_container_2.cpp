// 2_container_2: 99 page
#include <iostream>
using namespace std;

// 방법 1. 최상위 클래스 (object)의 포인터를 보관하자.
class object {};

// 장점: 템플릿이 아니다. 코드메모리가 증가하지 않는다.
// 단점: 1. 타입 안정성이 부족하다. 잘못 사용해도 에러가 나지 않는다.
//       2. class 타입이 아닌 primitive type을 저장할 수 없다. 그래서 java에는 int와 Integer가 있다.
//       3. 데이터를 꺼낼 때 캐스팅이 필요하다.

// 라이브러리 내의 모든 클래스는 obejct로부터 파생되기로 약속
class Point  : public object {};
class Rect   : public object {};
class Dialog : public object {};

// 싱글리스트를 만들어봅시다
struct Node
{
	object*   data;
	Node* next;
	Node(object* d, Node* n) : data(d), next(n) { }
};

class slist
{
	Node* head = 0;
public:
	void push_front(object* n) { head = new Node(n, head); }
	object* front() { return head->data; }
};

int main()
{
	slist s;
	s.push_front(new Point);
	s.push_front(new Point);
	s.push_front(new Dialog); // 이 순간의 메모리 구조는?

	Dialog* p = (Dialog*)s.front();
}