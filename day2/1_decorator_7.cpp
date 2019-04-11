// 1_decorator_7
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
class NetworkStream : public IStream
{
	// SOCKET sock
public:
	NetworkStream(string ip, short port)
	{
		// ip, port에 접속
	}
	~NetworkStream() { }

	void write(const char* s, int bytes)
	{
		cout << s << " 데이타 전송" << endl;
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
	EncryptDecorator ed(&fs);
	ed.write("hello", 5);

	NetworkStream ns("127.1.1.1", 4000);
	EncryptDecorator ed2(&ns);
	ed2.write("hello", 5);
}
// C# 스트림 클래스 종류
// FileStream
// NetworkStream
// BufferedStream

// 스트림 데코레이터 종류
// ZipDecorator
// XmlDecorator
// EncryptDecorator

// 핵심: 객체와 기능 추가 객체는 동일한 기반 클래스를 사용한다!!
//       포장지는 객체를 포장하지만 포장된 객체도 포장할 수 있다.
//       객체와 포장지는 동일한 기반 클래스가 필요하다!!

// Composite 패턴과 Decorator 패턴의 클랫 구조는 동일합니다.
// 모두 재귀적 포함!
// 왜 재귀적 포함을 사용하는가?
// 복합객체를 만들려고-> composite
// 동적 기능을 추가하려면 -> decorator

