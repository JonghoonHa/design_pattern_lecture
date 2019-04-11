// 5_EditBox_2 - 28 page
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

// Step 3. Validation 정책은 교체 가능하게 설계되어야 한다.
// 방법 1. 변하는 것(validation)정책을 가상함수로!!
class EditBox
{
	string data;
public:
	virtual bool validate(char c)
	{
		return isdigit(c);
	}
	string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();
			if (c == 13) break; // enter 입력

			if (validate(c)) // 정책을 담은 가상함수 호출
			{
				data.push_back(c);
				cout << c;
			}
		}
		cout << endl;
		return data;
	}
};

// 파생 클래스를 만들어서 정책을 담은 가상함수 변경
class AddressEdit : public EditBox
{
public:
	virtual bool validate(char c) { return true; }
};

int main()
{
	// EditBox e;
	AddressEdit e;
	while (1)
	{
		string s = e.getData();
		cout << s << endl;
	}
}

