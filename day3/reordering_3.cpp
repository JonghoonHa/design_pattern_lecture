// reordering_3
// cl reordering.cpp /FAs /c 
// "/FAa" �ɼ��� ����� �ҽ��� �����϶�� �ǹ�
// "/c" �ɼ��� ��ũ���� ���� �����ϸ�!

// cl reordering.cpp /FAs /c /02 
// "/O2":  �ӵ��� ���� ����ȭ.. �Ϲ������� ���� ���� �����
#include <atomic>
using namespace std;
int a = 0;
int b = 0;

void foo()
{
	a = b + 1;
	// C+11���� �޸� �潺�� ǥ������ �����մϴ�.
	atomic_thread_fence(memory_order_seq_cst);
	b = 10;
}
