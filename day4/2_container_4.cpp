// 2_container_4: 99 page
#include <iostream>
using namespace std;

// ��� 3. thin template
// ���ۿ��� 'C++ Idioms' �˻��ϸ� ù ��° ��ũ
// Architecture: ��� ����, OS ����, �Ը� ū �ý��� ���� ���
// Design Pattern: �߰� �Ը��� ��ü���� �ڵ� ���. �� �������� �ڵ� ���
// Idioms: �ұԸ��� Ư�� ���� �ڵ� ���
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
// slistimp�� ���� ����ϸ� �׻� ĳ������ �ؾ��Ѵ�... �ʹ� ������!
// ĳ���ø� å������ Ŭ���� ���ø��� ������
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