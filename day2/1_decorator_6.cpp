// 1_decorator_6
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

// Stream 과 decorator 들의 공통의 기반 클래스
struct IStream
{
	virtual void write(const char*, int size) = 0;
	virtual ~IStream() {}
};
class FileStream : public IStream
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
		cout << s << " file 에 쓰기" << endl;
	}
};

//전달된 data에 압축기능을 수행하는 decorator
class ZipDecorator : public IStream
{
	IStream* stream;
public:
	ZipDecorator(IStream* s) : stream(s) {}

	void write(const char* s, int byte)
	{
		// data를 압축한 후에
		char buf[256] = "압축: ";
		strcat(buf, s);
		// 원본 스트림에 쓴다.
		stream->write(buf, strlen(buf));
	}
};
class EncryptDecorator : public IStream
{
	IStream* stream;
public:
	EncryptDecorator(IStream* s) : stream(s) {}

	void write(const char* s, int byte)
	{
		char buf[256] = "암호화: ";
		strcat(buf, s);
		stream->write(buf, strlen(buf));
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("hello", 5);

	// 암호화하는 기능을 추가하는 decorator
	EncryptDecorator ed(&fs);
	ed.write("hello", 5);

	// 압축하는 기능을 추가하는 decorator
	ZipDecorator zd(&ed);
	zd.write("hello", 5);
}