// 2_flyweight_2: 167 page
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
	static map<string, Image*> image_map;

public:
	void Draw() { cout << "Draw " << url << endl; }
	// �ڽ��� �����ϴ� static ����Լ� -> ���� ���� ���~~
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
	// static ��� �Լ��� ���ؼ� ��ü�� �����մϴ�.
	// iOS ���α׷����� Image ��ü�� ���� �� �Ʒ�ó�� �Ѵ�.
	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();

	// s1, s2�� ���� �ּҴ� ������? �ٸ���?  -> ����!!!!���� string�� ���� �� ������ ����ϱ� ����
	const char* s1 = "hello";
	const char* s2 = "hello";

	printf("%p, %p\n", s1, s2);
}