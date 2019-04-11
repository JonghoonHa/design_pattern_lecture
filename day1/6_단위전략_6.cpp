#include <iostream>
// #include <string>
using namespace std;

// string 의 원리
template<typename T,                     // char? wchar_t 중 한 개.. 즉 유니코드 고려
	     typename traits=char_traits<T>, // 비교 단위 전략
	     typename Alloc = allocator<T>>  // 메모리 할당 전략

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

	if (s1 == s2) // s1.operator==(s2) 함수에서 비교
		cout << "same" << endl;
	else
		cout << "not same" << endl;
}