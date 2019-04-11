// 1_decorator_7
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
class NetworkStream : public IStream
{
	// SOCKET sock
public:
	NetworkStream(string ip, short port)
	{
		// ip, port�� ����
	}
	~NetworkStream() { }

	void write(const char* s, int bytes)
	{
		cout << s << " ����Ÿ ����" << endl;
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
	EncryptDecorator ed(&fs);
	ed.write("hello", 5);

	NetworkStream ns("127.1.1.1", 4000);
	EncryptDecorator ed2(&ns);
	ed2.write("hello", 5);
}
// C# ��Ʈ�� Ŭ���� ����
// FileStream
// NetworkStream
// BufferedStream

// ��Ʈ�� ���ڷ����� ����
// ZipDecorator
// XmlDecorator
// EncryptDecorator

// �ٽ�: ��ü�� ��� �߰� ��ü�� ������ ��� Ŭ������ ����Ѵ�!!
//       �������� ��ü�� ���������� ����� ��ü�� ������ �� �ִ�.
//       ��ü�� �������� ������ ��� Ŭ������ �ʿ��ϴ�!!

// Composite ���ϰ� Decorator ������ Ŭ�� ������ �����մϴ�.
// ��� ����� ����!
// �� ����� ������ ����ϴ°�?
// ���հ�ü�� �������-> composite
// ���� ����� �߰��Ϸ��� -> decorator

