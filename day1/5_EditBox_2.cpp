// 5_EditBox_2 - 28 page
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

// Step 2. Validation 기능 추가
class EditBox
{
	string data;
public:
	string getData()
	{
		data.clear();

		while (1)
		{
			char c = _getch();
			if (c == 13) break; // enter 입력

			if (isdigit(c))
			{
				data.push_back(c);
				cout << c;
			}
		}
		cout << endl;
		return data;
	}
};
int main()
{
	EditBox e;
	while (1)
	{
		string s = e.getData();
		cout << s << endl;
	}
}