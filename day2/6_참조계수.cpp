// 6_참조계수
#include <vector>
using namespace std;

class Car {};

vector<Car*> v;

void foo()
{
	Car* p = new Car;
	v.push_back(p);

	delete p;
}

int main()
{
	foo();
}