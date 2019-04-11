// 1_decorator_5
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class FileStream
{
	FILE* file;
public:
	FileStream(string name, string mode = "wt")
	{
		file = fopen(name.c_str(), mode.c_str());
	}
	~FileStream() { fclose(file); }

	void write(const char* s, int bytes)
	{
		cout << s << " file ¿¡ ¾²±â" << endl;
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("hello", 5);
}