// 3_�Լ�������_1
// �ٽ� 1. ����Լ��� ���ڷ� this�� �߰��˴ϴ�.
//      2. static ��� �Լ��� ���ڷ� this�� �߰����� �ʴ´�.
class Point
{
	int x, y;
public:
	void set(int a, int b) // void set(Point* this, int a, int b)
	{
		x = a;             // this->x = a;
		y = b;             // this->y = b; ���� �����ϵȴ�.
	}
	static void foo(int a) // void foo(int a) // this�� ����. ��������Ϳ� ������ �Ұ����ϴ�. ļ... python�ϰ� �Ȱ���
	{
		x = a; // this->x �� �Ǿ�� �ϴµ� this�� ����.
		       // �׷��� static ��� �Լ��� ��� �����Ϳ� ���� �ȵȴ�.
	}
};

int main()
{
	Point::foo(10); // ��ü ���� ȣ�� ����

	Point p1, p2;
	p1.set(10, 20); // ������ �����غ���
	                // set(&p1, 10, 20)
	                // push 20
	                // push 10
	                // mov ecx, &p1 // ��ü�ּҴ� ��κ� �������ͷ�!
	                // call Point::set
}