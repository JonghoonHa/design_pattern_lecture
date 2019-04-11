#include <iostream>
using namespace std;

// 인터페이스는 쉽게 변경할 수 없다
// 인터페이스 불변의 법칙

struct IMP3
{
    virtual void Play() = 0;
    virtual void Stop() = 0;
    virtual ~IMP3() {}
};

class IPod :  public IMP3
{
public:
    void Play() { cout << "Play MP3" << endl;}
    void Stop() { cout << "Stop MP3" << endl;}
};

class People
{
public:
    void UseMP3(IMP3* p )
    {
        p->Play();

		p->PlayOneMinute(); // 요구사항 추가
    }
};


int main()
{

}






//
