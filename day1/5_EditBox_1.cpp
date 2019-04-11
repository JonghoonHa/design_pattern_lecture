// 5_EditBox_1 - 28 page
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

class EditBox
{
	string data;
public:
	string getData()
	{
		cin >> data;
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