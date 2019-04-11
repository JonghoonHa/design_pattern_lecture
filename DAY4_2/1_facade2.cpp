#include <iostream>
#include <WinSock2.h>
using namespace std;

// SRP: Single Responsibility Principle, 단일 책임의 원칙
//      하나의 클래스에는 하나의 책임만 있는 것이 좋다.

// network 라이브러리의 초기화와 cleanup을 담당.
class NetworkInit
{
public:
	NetworkInit()
	{
		WSADATA w;
		WSAStartup(0x202, &w);
	}
	~NetworkInit()
	{
		WSACleanup();
	}
};

// IP 주소 관리.
class IPAddress
{
	struct sockaddr_in addr;
public:
	IPAddress(const char* ip, short port)
	{
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip);
	}
	struct sockaddr* getRawAddress() { return (struct sockaddr*)&addr; }
};

// socket 프로그래밍의 일반적인 절차.
class Socket
{
	int sock;
public:
	Socket(int type) { sock = socket(PF_INET, type, 0); }

	void Bind(IPAddress* ip)
	{
		::bind(sock, ip->getRawAddress(), sizeof(struct sockaddr_in));
	}
	void Listen() { ::listen(sock, 5); }
	void Accept()
	{
		struct sockaddr_in addr2 = { 0 };
		int sz = sizeof(addr2);
		accept(sock, (struct sockaddr*)&addr2, &sz);
	}
};
class TCPServer
{
	NetworkInit init;
	Socket sock;
public:
	TCPServer() : sock(SOCK_STREAM) {}

	void Start(const char* ip, short port)
	{
		IPAddress addr(ip, port);
		sock.Bind(&addr);
		sock.Listen();
		sock.Accept();
	}
};
int main()
{
	NetworkInit init;
	IPAddress ip("127.0.0.1", 4000);
	Socket sock(SOCK_STREAM); // TCP
	sock.Bind(&ip);
	sock.Listen();
	sock.Accept();
}









//
