// 2_flyweight: 167 page
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;

// flyweight pattern: 속성이 동일한 객체는 공유할 수 있게 설계하자.

class Image
{
	string url;
public:
	Image(string s) : url(s)
	{
		cout << "Downloading " << url << endl;
		this_thread::sleep_for(3s); // <thread> 헤더 필요. 3s: chrono 헤더, namespace 필요
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