// 1_������_2.cpp

// protected ������: �ڽ��� ��ü�� ������ ���� ������
//                   �Ļ� Ŭ������ ��ü�� ���� �� �ְ� �ϴ� ���
//                   �����̶�� ������ �߻����� �������� ��ü�� �������� �ʴ´�.

class Animal
{
protected:
	Animal() {}
};

class Dog : public Animal
{
public:
	Dog() {}
};

int main()
{
	// ���� �� ������?
	Animal a; // error
	Dog d; // ok
}