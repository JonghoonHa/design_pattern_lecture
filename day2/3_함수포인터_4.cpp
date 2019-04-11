// 3_함수포인터_4

// 클래스템플릿 vs 함수 템플릿

template<typename T> int square(T a)
{
	return a * a;
}

template<typename T> class List
{
public:
	List(int sz, T value) {}
};
// 함수 템플릿: 타입을 명시하지 않아도 함수인자로 추론 가능
// 클래스 템플릿: 반드시 타입을 명시해야 한다.

// 클래스 템플릿을 직접 사용하면 복잡해보인다.
// 클래스 템플릿을 만드는 함수템플릿을 제공하자 - "Object Generator"

template<typename T> List<T> makeList(int sz, T value)
{
	return new List<T>(sz, value);
}

int main()
{
	square<int>(3);
	square(3); // 3을 가지고 T의 타입을 추론한다.

	// List<int> s1(10, 0);
	// List s1(10, 0);
	makeList(10, 0);
}