// 3_�߻�Ŭ���� 10 page

// �߻� Ŭ���� (abstract class): ���� �����Լ��� �� �� �̻��� Ŭ����
// Ư¡: ��ü�� ���� �� ����.
// �ǵ�: Ư�� �Լ��� �ݵ�� ������ �����ϴ� ��.
class Shape
{
public:
	virtual void Draw() = 0; // ���� �����Լ� (pure virtual function)
};

class Rect : public Shape // ��� Ŭ�������� ���� ���� ���� �����Լ��� �����θ� �������� ������ ���� �߻�Ŭ����
{
public:
};                        // ��üȭ (concrete) Ŭ������ �Ƿ��� Draw() �����θ� �����ؾ� �Ѵ�.

int main()
{
	Shape s; // error. �߻� Ŭ������ ��ü�� ���� �� ����.
	Rect  r;
}