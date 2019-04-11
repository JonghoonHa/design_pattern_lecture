// 2_menuevent_3

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// event 처리는 결국 변해야 하는 코드이다.
// 변하는 것을 다른 클래스로!

// 방법 2. java, 안드로이드 앱 등에서 사용하는 방식: 'Listener'라는 기술! (사실은 strategy pattern)
// 메뉴 이벤트를 처리하고싶은 모든 클래스는 아래 인터페이스를 구현해야한다.
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
		// 메뉴가 선택된 사실을 등록된 리스너에게 알려준다
		// pListener->OnCommand(id);

		for (int i = 0; i < v.size(); i++)
			v[i]->OnCommand(id);
	}
};
// --------------------------------------------------------------------------
// 메뉴의 이벤트 처리하려면 반드시 IMenuListener 인터페이스를 구현한 객체를 만들어야한다.
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
	m2.addListener(&cam); // 메뉴에 listener 등록
	m1.command();
	m2.command();
}
