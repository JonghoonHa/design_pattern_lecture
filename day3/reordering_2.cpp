// reordering_2
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
	// 위의 코드가 아래 부분의 코드와 순서를 변경하지 못하게 펜스를 설치한다.
	__asm { mfence }
	b = 10;
}
