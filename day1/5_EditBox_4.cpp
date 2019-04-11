// 5_EditBox_4 - 34 page
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

// 변하는 것을 분리하는 2가지 기술
// 1. 변하는 것을 가상함수로 - 'template method'
// 2. 변하는 것을 다른 클래스로 - 변해야 하므로 교체가능해야 한다.
//                                인터페이스 기반의 약한 결합

struct IValidator
{
	virtual bool validate(string s, char c) = 0;
	virtual bool iscomplete(string s) { return true; }
	virtual ~IValidator() {}
};

// 주민번호: 901 1 확인
class EditBox
{
	string data;

	// -------------------------------------------
	IValidator* pVal = 0;
public:
	void setValidator(IValidator* p) { pVal = p; }
	// -------------------------------------------

	string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();
			if (c == 13 && (pVal == 0 || pVal->iscomplete(data))) break; // enter 입력

			if ( pVal == 0 || pVal->validate(data, c) )
			{
				data.push_back(c);
				cout << c;
			}
		}
		cout << endl;
		return data;
	}
};

// 다양한 정책을 가진 validator 들을 제공합니다.

class LimitDigitValidator : public IValidator
{
	int value;
public:
	LimitDigitValidator(int v) : value(v) {}

	virtual bool validate(string s, char c) override
	{
		return s.size() < value && isdigit(c);
	}

	// 아래 함수는 필요한 경우만 재정의!!!
	virtual bool iscomplete(string s) override
	{
		return s.size() == value;
	}
};
int main()
{
	EditBox e;
	LimitDigitValidator v(5);
	LimitDigitValidator v2(10); // 필요할 때마다 정책 변경 가능
	e.setValidator(&v);
	// e.setValidator(&v2);
	 
	while (1)
	{
		string s = e.getData();
		cout << s << endl;
	}
}