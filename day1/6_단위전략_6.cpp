#include <iostream>
// #include <string>
using namespace std;

// string �� ����
template<typename T,                     // char? wchar_t �� �� ��.. �� �����ڵ� ���
	     typename traits=char_traits<T>, // �� ���� ����
	     typename Alloc = allocator<T>>  // �޸� �Ҵ� ����

class basic_string
{
	T* buff;
public:
	bool operator==(const basic_string& s)
	{
		return traits::compare(buff, s.buff);
	}
};
typedef basic_string<char> string;

int main()
{
	string s1 = "abcd";
	string s2 = "ABCD";

	if (s1 == s2) // s1.operator==(s2) �Լ����� ��
		cout << "same" << endl;
	else
		cout << "not same" << endl;
}