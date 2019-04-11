// 2_flyweight_3: 167 page
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <map>
using namespace std;
using namespace std::chrono;

// flyweight pattern: �Ӽ��� ������ ��ü�� ������ �� �ְ� ��������.

class Image
{
	string url;

	Image(string s) : url(s)
	{
		cout << "Downloading " << url << endl;
		this_thread::sleep_for(3s);
	}

public:
	void Draw() { cout << "Draw " << url << endl; }

	friend class Factory;
};

// Image�� ����� Ŭ���� - Factory ����
class Factory
{
	map < string, Image*> image_map;
public:
	Image* CreateImage(string url)
	{
		auto p = image_map.find(url);
		if ( p == image_map.end() )
			image_map[url] = new Image(url);

		return image_map[url];
	}
};

int main()
{
	Factory factory; // �Ϲ������� �̱������� �����.

	Image* img1 = factory.CreateImage("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = factory.CreateImage("www.naver.com/a.png");
	img2->Draw();

}