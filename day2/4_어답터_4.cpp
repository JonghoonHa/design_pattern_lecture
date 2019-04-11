// 4_�����_4
// 4_�����_3
#include <iostream>
#include <list>
#include <vector>
#include <deque>
using namespace std;
/*
// Ŭ���� ������̴�. ���ο� C st�� �����������ϱ�!
template<typename T, typename C= deque<T>> class stack
{
	C st;
public:
	inline void push(const T& a) { st.push_back(a); }
	inline void pop() { st.pop_back(); }
	inline T&   top() { return st.back(); }
};
*/

#include <stack> // C++ ǥ���� ����.. ���� �ۼ� �ڵ�ó�� �����Ǿ��ִ�!
                 // �׷��� 'stack adapter'��� �θ���.
int main()
{
	stack<int> s2;              // �⺻���� deque<int>�� ����ϴ� ����
	stack<int, list<int>> s;    // list�� �������� �����ش޶�
	stack<int, vector<int>> s1; // vector�� �������� �����ش޶�
	s.push(10);
	s.push(20);
}