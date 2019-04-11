// 2_flyweight_2: 167 page
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
	static map<string, Image*> image_map;

public:
	void Draw() { cout << "Draw " << url << endl; }
	// 자신을 생성하는 static 멤버함수 -> 아주 좋은 기술~~
	static Image* Create(string url)
	{
		if (image_map[url] == nullptr)
			image_map[url] = new Image(url);
		return image_map[url];
	}
};
map<string, Image*> Image::image_map;

void main()
{
	// static 멤버 함수를 통해서 객체를 생성합니다.
	// iOS 프로그램에서 Image 겍체를 만들 때 아래처럼 한다.
	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();

	// s1, s2가 가진 주소는 같을까? 다를까?  -> 같다!!!!ㄷㄷ string에 대해 이 패턴을 사용하기 때문
	const char* s1 = "hello";
	const char* s2 = "hello";

	printf("%p, %p\n", s1, s2);
}