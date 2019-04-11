// 5_proxy_2
#include <iostream>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

// 원격지의 서버(IPC 또는 네트워크 서버)를 대신하는 클래스
// remote proxy
// proxy는 함수 호출을 명령코드로 변경해서 서버에 전달합니다.
// stub은 도착한 명령코드를 다시 함수 호출로 변경

// 장점
// 1. IPC의 세부 구조를 알 필요 없다.
// 2, Cache 등의 추가 기능을 제공할 수 있다.
// 3. RPC(Remote Procedure Call), RMI(Remote Method Invocation)을 만드는 것!
class Calc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};
int main()
{
	// 서버를 대신하는 객체(Proxy)를 생성합니다.
	Calc* pCalc = new Calc;
	cout << pCalc->Add(1, 2) << endl;
	cout << pCalc->Sub(1, 2) << endl;
}