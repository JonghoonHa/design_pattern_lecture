// 2_flyweight_3: 167 page
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <map>
using namespace std;
using namespace std::chrono;

// flyweight pattern: 속성이 동일한 객체는 공유할 수 있게 설계하자.

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

// Image를 만드는 클래스 - Factory 도입
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
	Factory factory; // 일반적으로 싱글톤으로 만든다.

	Image* img1 = factory.CreateImage("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = factory.CreateImage("www.naver.com/a.png");
	img2->Draw();

}