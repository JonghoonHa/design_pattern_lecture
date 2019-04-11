#include <iostream>
using namespace std;

// 방법 1. item 상태에 따라 if-else문
// 새로운 아이템이 등장하면 모든 동작 함수에 항목 추가
// 좋지 않다

class Character
{
    int gold = 0;
    int item = 0;
public:
    void run()
    {
        if ( item == 1)
            cout << "run"    << endl;
        else if ( item == 2 )
            cout << "fast run" << endl;
    }
    void attack()
    {
        if ( item == 1)
             cout << "attack" << endl;
        else if ( item == 2 )
             cout << "attack2" << endl;
    }
};

int main()
{
    Character* p = new Character;
    p->run();
    p->attack();
}
