// 5_proxy_1: 78 page
#include <iostream>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

int main()
{
	// 1. IPC 서버를 찾습니다.
	int server = ec_find_server("Calc"); // 서버 이름
	
	cout << "서버 번호: " << server << endl;

	// 2. 서버에 명령을 전달합니다.
	int n1 = ec_send_server(server, 1, 1, 2);
	int n2 = ec_send_server(server, 2, 1, 2);

	cout << n1 << endl;
	cout << n2 << endl;
}