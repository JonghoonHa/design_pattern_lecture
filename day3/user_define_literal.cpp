// user_define_literal
#include <iostream>
using namespace std;

class Weight
{
	int value;
public:
	Weight(int v) : value(v) {}
};

// user define literal 규칙
// 정수 리터럴: unsigned long long 인자 사용
// 문자열 리터럴: const char* 인자 사용
// 사용자 정의형은 첫 글자에 무조건 '_'붙여야 한다. 기본형과 충돌날 수 있음
Weight operator""_gram(unsigned long long v)
{
	return Weight(v);
}

int main()
{
	float f = 3.4f;

	Weight w = 3_gram; // operator""gram(3)가 호출됩니다. 오직 '상수 + 단위'의 조합에서만 가능!
}