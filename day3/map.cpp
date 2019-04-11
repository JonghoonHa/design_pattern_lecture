// map
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, string> m;

	// map�� �ֱ� 1.
	pair<string, string> p1("mon", "������");
	m.insert();

	// 2. make_pair
	m.insert(make_pair("tue", "ȭ����"));

	// 3. [] ������
	m["wed"] = "������";

	// 4. C++11 : {}
	m.insert({ "tue", "�����" });
	m.emplace("sat", "�����"); // ���� ���� ���! �ӽ� ��ü �ȸ���~~

	// �˻�
	if (m["fri"] == "") {} // ������ fri Ű ���� ����, value�� ����Ʈ �����ڷ� ����
	auto p = m.find("fri"); // ������ �ƴ� �˻�.
}