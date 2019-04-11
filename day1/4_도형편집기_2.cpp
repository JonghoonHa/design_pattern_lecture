// 4_도형편집기_2 - 15 page

#include <iostream>
#include <vector>
using namespace std;

// 5. 다형성 기반(가상함수)의 코드는 OCP를 만족한다.
// 6. 객체지향 설계원칙: ~ 를 지켜라. 5대 원칙
//    다지인 패턴: ~ 지키려면 이런 방법으로 코딩해라. - 23개의 패턴
// 7. Prototype 패턴: 객체를 만들 때, 견본을 만들고, 견본의 복사를 통해서 객체를 만드는 패턴. 
//                    Clone()가상함수. C#에는 대부분 클래스에 Clone()함수가 있습니다.
//                    swift 에는 copy()멤버 함수가 있습니다.

class Shape
{
public:
	virtual void Draw() { cout << "Draw Shape" << endl; }
	
	// 자신의 복사본을 만드는 가상함수는 항상 편리하다
	virtual Shape* Clone() { return new Shape(*this); }
};
class Rect : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Rect" << endl; }
	virtual Shape* Clone() { return new Rect(*this); }
};
class Circle : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Circle" << endl; }
	virtual Shape* Clone() { return new Circle(*this); }
};
class Triangle : public Shape
{
public:
	virtual void Draw() override { cout << "Draw Triangle" << endl; }
	virtual Shape* Clone() { return new Triangle(*this); }
};
int main()
{
	vector<Shape*> v;

	while (1)
	{
		int cmd;
		cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 8)
		{
			cout << "몇 번째 도형을 복사할까요? >> ";
			int k;
			cin >> k;

			// k번째 도형의 복사본을 만들어서 v에 추가합니다.

			v.push_back(v[k]->Clone()); // ok. 다형성을 활용. OCP를 만족하는 좋은 코드
			
		}
		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
				v[i]->Draw(); // 다형성(polymorphism). 동일 함수의 호출의 모양이 상황에 따라 다른 함수를 호출하는 것. OCP를 만족하는 것이 장점!
		}
	}
}