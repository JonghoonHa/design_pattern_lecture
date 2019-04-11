// reordering
// cl reordering.cpp /FAs /c 
// "/FAa" 옵션은 어셈블리 소스를 생성하라는 의미
// "/c" 옵션은 링크하지 말고 컴파일만!

// cl reordering.cpp /FAs /c /02 
// "/O2":  속도를 위한 최적화.. 일반적으로 가장 많이 사용함
int a = 0;
int b = 0;

void foo()
{
	a = b + 1;
	b = 10;
}

/*
// 다른 스레드가 아래 함수를 실행합니다.
void goo()
{
	if (b == 10) 
	{
		// a가 1이라고 확신할 수 있을까?
	}
}
*/