// 5_EditBox_4 - 34 page
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

// ���ϴ� ���� �и��ϴ� 2���� ���
// 1. ���ϴ� ���� �����Լ��� - 'template method'
// 2. ���ϴ� ���� �ٸ� Ŭ������ - ���ؾ� �ϹǷ� ��ü�����ؾ� �Ѵ�.
//                                �������̽� ����� ���� ����

struct IValidator
{
	virtual bool validate(string s, char c) = 0;
	virtual bool iscomplete(string s) { return true; }
	virtual ~IValidator() {}
};

// �ֹι�ȣ: 901 1 Ȯ��
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
			if (c == 13 && (pVal == 0 || pVal->iscomplete(data))) break; // enter �Է�

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

// �پ��� ��å�� ���� validator ���� �����մϴ�.

class LimitDigitValidator : public IValidator
{
	int value;
public:
	LimitDigitValidator(int v) : value(v) {}

	virtual bool validate(string s, char c) override
	{
		return s.size() < value && isdigit(c);
	}

	// �Ʒ� �Լ��� �ʿ��� ��츸 ������!!!
	virtual bool iscomplete(string s) override
	{
		return s.size() == value;
	}
};
int main()
{
	EditBox e;
	LimitDigitValidator v(5);
	LimitDigitValidator v2(10); // �ʿ��� ������ ��å ���� ����
	e.setValidator(&v);
	// e.setValidator(&v2);
	 
	while (1)
	{
		string s = e.getData();
		cout << s << endl;
	}
}