// 2_menuevent_3

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// event ó���� �ᱹ ���ؾ� �ϴ� �ڵ��̴�.
// ���ϴ� ���� �ٸ� Ŭ������!

// ��� 2. java, �ȵ���̵� �� ��� ����ϴ� ���: 'Listener'��� ���! (����� strategy pattern)
// �޴� �̺�Ʈ�� ó���ϰ���� ��� Ŭ������ �Ʒ� �������̽��� �����ؾ��Ѵ�.
struct IMenuListener
{
	virtual void OnCommand(int id) = 0;
	virtual ~IMenuListener() {}
};

class MenuItem
{
	string title;
	int id;
	vector<IMenuListener*> v;
public:
	// void setListener(IMenuListener* p) { pListener = p; }
	void addListener(IMenuListener* p) { v.push_back(p); }

	MenuItem(string s, int n) : title(s), id(n) {}

	virtual void command()
	{
		// �޴��� ���õ� ����� ��ϵ� �����ʿ��� �˷��ش�
		// pListener->OnCommand(id);

		for (int i = 0; i < v.size(); i++)
			v[i]->OnCommand(id);
	}
};
// --------------------------------------------------------------------------
// �޴��� �̺�Ʈ ó���Ϸ��� �ݵ�� IMenuListener �������̽��� ������ ��ü�� �������Ѵ�.
class Camera : public IMenuListener
{
public:
	virtual void OnCommand(int id)
	{
		cout << "Camera OnCommand" << endl;
		switch (id)
		{
		case 11: cout << "11" << endl; break;
		case 12: cout << "12" << endl; break;
		}
	}
};
int main()
{
	MenuItem m1("HD", 11);
	MenuItem m2("UHD", 12);
	Camera cam;
	m1.addListener(&cam);
	m2.addListener(&cam); // �޴��� listener ���
	m1.command();
	m2.command();
}
