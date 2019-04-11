// 1_decorator_6
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

// Stream �� decorator ���� ������ ��� Ŭ����
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
		cout << s << " file �� ����" << endl;
	}
};

//���޵� data�� �������� �����ϴ� decorator
class ZipDecorator : public IStream
{
	IStream* stream;
public:
	ZipDecorator(IStream* s) : stream(s) {}

	void write(const char* s, int byte)
	{
		// data�� ������ �Ŀ�
		char buf[256] = "����: ";
		strcat(buf, s);
		// ���� ��Ʈ���� ����.
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
		char buf[256] = "��ȣȭ: ";
		strcat(buf, s);
		stream->write(buf, strlen(buf));
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("hello", 5);

	// ��ȣȭ�ϴ� ����� �߰��ϴ� decorator
	EncryptDecorator ed(&fs);
	ed.write("hello", 5);

	// �����ϴ� ����� �߰��ϴ� decorator
	ZipDecorator zd(&ed);
	zd.write("hello", 5);
}