// 2_container_2: 99 page
#include <iostream>
using namespace std;

// ��� 1. �ֻ��� Ŭ���� (object)�� �����͸� ��������.
class object {};

// ����: ���ø��� �ƴϴ�. �ڵ�޸𸮰� �������� �ʴ´�.
// ����: 1. Ÿ�� �������� �����ϴ�. �߸� ����ص� ������ ���� �ʴ´�.
//       2. class Ÿ���� �ƴ� primitive type�� ������ �� ����. �׷��� java���� int�� Integer�� �ִ�.
//       3. �����͸� ���� �� ĳ������ �ʿ��ϴ�.

// ���̺귯�� ���� ��� Ŭ������ obejct�κ��� �Ļ��Ǳ�� ���
class Point  : public object {};
class Rect   : public object {};
class Dialog : public object {};

// �̱۸���Ʈ�� �����ô�
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
	s.push_front(new Dialog); // �� ������ �޸� ������?

	Dialog* p = (Dialog*)s.front();
}