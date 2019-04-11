// 9_ApplicationFramework - 46 page
#include <iostream>
using namespace std;

// 라이브러리: 프로그램 작성에 필요한 도구만 제공
// 프레임워크: 도구 + 미리 정의된 실행 흐름.
// 아래 코드는 MFC 라이브러리의 원리입니다.

// 모든 것을 객체지향으로 하고싶다.
// 아래는 라이브러리 설계자의 코드

class CWinApp; // 클래스 전방선언. (forward declaration)
               //  전방선언만 있으면 포인터 변수를 만들 수 있습니다.

CWinApp* g_app = 0; // 무조건 포인터 변수여야 한다. 그렇지 않으면CWinApp의 메모리 할당을 위한 크기를 알아야 하는데 문제된다.

class CWinApp
{
public:
	CWinApp() { g_app = this; }
	virtual bool InitInstance() { return false; }
	virtual int ExitInstance() { return 0; }
	virtual int Run()          { return 0; }
};
CWinApp* AfxGetApp() { return g_app; }

int main() // main이 멤버 함수일 수 없어서 부득이하게 밖으로 빼냄
{
	CWinApp* pApp = AfxGetApp();
	if (pApp->InitInstance())
		pApp->Run();
	pApp->ExitInstance();
}

// 여기서부터는 위의 라이브러리를 사용하는 사용자의 코드입니다.
// 규칙 1. CWinApp의 파생 클래스를 만들어라.
//      2. InitInstance() 가상함수를 재정의하라.
//      3. 사용자가 만든 클래스의 전역변수를 생성하라.

class CMyApp : public CWinApp
{
public:
	virtual bool InitInstance()
	{
		cout << "프로그램 초기화 실행" << endl;
		return true;
	}
	virtual int ExitInstance()
	{
		cout << "자원 해지" << endl;
		return 0;
	}
};
CMyApp theApp;
// 실행순서
// 1. 기반 클래스인 CWinApp 생성자
// 2. 전역변수 theApp 생성자, 