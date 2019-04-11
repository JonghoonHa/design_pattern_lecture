// 2_flyweight: 167 page
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;

// flyweight pattern: �Ӽ��� ������ ��ü�� ������ �� �ְ� ��������.

class Image
{
	string url;
public:
	Image(string s) : url(s)
	{
		cout << "Downloading " << url << endl;
		this_thread::sleep_for(3s); // <thread> ��� �ʿ�. 3s: chrono ���, namespace �ʿ�
	}
	void Draw() { cout << "Draw " << url << endl; }
};

void main()
{
	Image* img1 = new Image("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = new Image("www.naver.com/a.png");
	img2->Draw();
}