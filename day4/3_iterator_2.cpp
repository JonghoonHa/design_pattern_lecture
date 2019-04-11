#include <iostream>
using namespace std;

template<typename T> struct Node
{
	T   data;
	Node* next;
	Node(T d, Node* n) : data(d), next(n) { }
};

// iterator : �����̳��� ��Ҹ� ���ʴ�� �����Ҷ� ����ϴ� ��ü
// ��� �����̳��� iterator�� ������ �����ؾ��Ѵ�.
// iterator�� �������̽�
// C# 1.0 ���� - object ��� �����̳�
/*
struct IEnumerator
{
	virtual bool MoveNext() = 0; // �������� �̵�
	virtual object* Object() =  0;     // �� ������
	virtual ~IEnumerator() = 0; 
};
*/
// C#2.0, �ＺŸ����(C++).. ���ø� ��� �������̽�
template<typename T> struct IEnumerator
{
	virtual bool MoveNext() = 0; // �������� �̵�
	virtual T Object() = 0;     // �� ������
	virtual ~IEnumerator() {};
};

// ��� �����̳ʴ� �ݺ��ڸ� ������ �־�� �Ѵ�.
// �����̳��� �������̽�
template<typename T> struct IEnumerable
{
	virtual IEnumerator<T>* GetEnumerator() = 0;
	virtual ~IEnumerable() {}
};

// slist�� �ݺ���
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




// ��� �����̳ʴ� �ݺ��ڸ� ������ �־�� �Ѵ�.

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




