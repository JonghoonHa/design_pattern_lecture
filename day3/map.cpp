// map
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, string> m;

	// map에 넣기 1.
	pair<string, string> p1("mon", "월요일");
	m.insert();

	// 2. make_pair
	m.insert(make_pair("tue", "화요일"));

	// 3. [] 연산자
	m["wed"] = "수요일";

	// 4. C++11 : {}
	m.insert({ "tue", "목요일" });
	m.emplace("sat", "토요일"); // 가장 좋은 방식! 임시 객체 안만들어서~~

	// 검색
	if (m["fri"] == "") {} // 없으면 fri 키 값을 생성, value는 디폴트 생성자로 생성
	auto p = m.find("fri"); // 생성이 아닌 검색.
}