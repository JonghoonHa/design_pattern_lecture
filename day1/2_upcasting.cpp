// 2_upcasting

class Animal
{
public:
	int age;
};

class Dog : public Animal
{
public:
	int color;
};

int main()
{
	Dog d;
	Dog*    p1 = &d; // ok
	Animal* p2 = &d; // ���Ŭ������ ������(����)�� �Ļ� Ŭ������ �ּҸ� ���� �� �ִ�... upcasting
	
	p2->age = 10;           // ok
	p2->color = 10;         // error. ��� Ŭ������ �����ͷ� ��� �� �Ļ� Ŭ���� ���� ����� ���� �ȵ�
	((Dog*)p2)->color = 10; //ok. �Ļ� Ŭ������ ĳ���� ���ָ� ������

	// ����
	vector<Dog*> v1; // Dog �� ����
	vector<Animal*> v2; // ��� ����(Animal �Ļ�Ŭ����) ����
}