// 5_EditBox_2 - 28 page
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

// Step 3. Validation ��å�� ��ü �����ϰ� ����Ǿ�� �Ѵ�.
// ��� 1. ���ϴ� ��(validation)��å�� �����Լ���!!
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
			if (c == 13) break; // enter �Է�

			if (validate(c)) // ��å�� ���� �����Լ� ȣ��
			{
				data.push_back(c);
				cout << c;
			}
		}
		cout << endl;
		return data;
	}
};

// �Ļ� Ŭ������ ���� ��å�� ���� �����Լ� ����
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

