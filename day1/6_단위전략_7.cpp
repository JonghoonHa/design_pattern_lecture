#include <iostream>
#include <string>
using namespace std;

// string 클래스가 상ㅇ할 비교 정책 클래스
struct MyTraits : public char_traits<char>
{
	static bool eq(char c1, char c2) { return toupper(c1) == toupper(c2); }
	static bool lt(char c1, char c2) { return toupper(c1) < toupper(c2); }
	static bool compare(const char* s1, const char* s2, int sz)
	{
		return _memicmp(s1, s2, strlen(s1));
	}
};
typedef basic_string<char, MyTraits> cistring;

int main()
{
	cistring s1 = "abcd";
	cistring s2 = "ABCD";

	if (s1 == s2) // s1.operator==(s2) 함수에서 비교
		cout << "same" << endl;
	else
		cout << "not same" << endl;
}