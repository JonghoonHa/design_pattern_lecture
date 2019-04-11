// 1_singleton_2: 123 page
#include <iostream>
using namespace std;

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor& c) = delete;
	void operator=(const Cursor&) = delete;

	static Cursor* sinstance;
public:
	static Cursor& getInstance()
	{
		if (sinstance == nullptr)
			sinstance = new Cursor;

		return *sinstance;
	}
};
Cursor* Cursor::sinstance = nullptr;

int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();
}