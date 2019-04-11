// reordering_3
// cl reordering.cpp /FAs /c 
// "/FAa" 옵션은 어셈블리 소스를 생성하라는 의미
// "/c" 옵션은 링크하지 말고 컴파일만!

// cl reordering.cpp /FAs /c /02 
// "/O2":  속도를 위한 최적화.. 일반적으로 가장 많이 사용함
#include <atomic>
using namespace std;
int a = 0;
int b = 0;

void foo()
{
	a = b + 1;
	// C+11부터 메모리 펜스를 표준으로 제공합니다.
	atomic_thread_fence(memory_order_seq_cst);
	b = 10;
}
