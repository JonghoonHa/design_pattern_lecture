// 5_proxy_1: 78 page
#include <iostream>
#include "ecourse.hpp"
using namespace std;
using namespace ecourse;

int main()
{
	// 1. IPC ������ ã���ϴ�.
	int server = ec_find_server("Calc"); // ���� �̸�
	
	cout << "���� ��ȣ: " << server << endl;

	// 2. ������ ����� �����մϴ�.
	int n1 = ec_send_server(server, 1, 1, 2);
	int n2 = ec_send_server(server, 2, 1, 2);

	cout << n1 << endl;
	cout << n2 << endl;
}