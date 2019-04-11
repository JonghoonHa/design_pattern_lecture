// 1_singleton: 123 page
#include <iostream>
using namespace std;

// singleton: ���� �ϳ��� ��ü�� �����ϰ�
//            �ý��� ��𿡼��� ������ ������� ���� ������ ��ü

// mayer�� �̱���: ���� �ϳ��� ��ü�� static ���������� �Ǿ��ִ� ���
//                 effective C++ �ø����� ���ڰ� ó�� ������ �ڵ�
class Cursor
{
	// ��Ģ 1. private ������
private:
	Cursor() {}
	// ��Ģ 2. ���� �� ���� ��ü�� ����� ��ȯ�ϴ� static ��� �Լ�
public:
	static Cursor& getInstance()
	{
		static Cursor instance;
		return instance;
	}
	// ��Ģ 3. ��������ڿ� ���Կ����ڸ� ����� �� ���� �Ѵ�.
	// ���� ���: private�� ���� �Ѵ�.
//private:
	// Cursor(const Cursor& c); // �����ΰ� ���� Cursor ���ο��� ����ϴ��� link error ������ ������.
	// ���γ��� ���: C++11 ���� '�Լ� ����'���� ���
	Cursor(const Cursor& c) = delete;
	void operator=(const Cursor&) = delete;
};

int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	// Cursor c3 = c1; // �� ���� ��������ڰ� ȣ��Ǵµ�, ȣ�� ���ϰ� �ؾ��Ѵ�
	// Cursor c1;
	// Cursor c2;
}