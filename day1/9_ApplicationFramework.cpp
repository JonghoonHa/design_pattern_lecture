// 9_ApplicationFramework - 46 page
#include <iostream>
using namespace std;

// ���̺귯��: ���α׷� �ۼ��� �ʿ��� ������ ����
// �����ӿ�ũ: ���� + �̸� ���ǵ� ���� �帧.
// �Ʒ� �ڵ�� MFC ���̺귯���� �����Դϴ�.

// ��� ���� ��ü�������� �ϰ�ʹ�.
// �Ʒ��� ���̺귯�� �������� �ڵ�

class CWinApp; // Ŭ���� ���漱��. (forward declaration)
               //  ���漱�� ������ ������ ������ ���� �� �ֽ��ϴ�.

CWinApp* g_app = 0; // ������ ������ �������� �Ѵ�. �׷��� ������CWinApp�� �޸� �Ҵ��� ���� ũ�⸦ �˾ƾ� �ϴµ� �����ȴ�.

class CWinApp
{
public:
	CWinApp() { g_app = this; }
	virtual bool InitInstance() { return false; }
	virtual int ExitInstance() { return 0; }
	virtual int Run()          { return 0; }
};
CWinApp* AfxGetApp() { return g_app; }

int main() // main�� ��� �Լ��� �� ��� �ε����ϰ� ������ ����
{
	CWinApp* pApp = AfxGetApp();
	if (pApp->InitInstance())
		pApp->Run();
	pApp->ExitInstance();
}

// ���⼭���ʹ� ���� ���̺귯���� ����ϴ� ������� �ڵ��Դϴ�.
// ��Ģ 1. CWinApp�� �Ļ� Ŭ������ ������.
//      2. InitInstance() �����Լ��� �������϶�.
//      3. ����ڰ� ���� Ŭ������ ���������� �����϶�.

class CMyApp : public CWinApp
{
public:
	virtual bool InitInstance()
	{
		cout << "���α׷� �ʱ�ȭ ����" << endl;
		return true;
	}
	virtual int ExitInstance()
	{
		cout << "�ڿ� ����" << endl;
		return 0;
	}
};
CMyApp theApp;
// �������
// 1. ��� Ŭ������ CWinApp ������
// 2. �������� theApp ������, 