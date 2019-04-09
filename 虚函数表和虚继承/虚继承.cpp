#include<iostream>

using namespace std;

class Animal {
public:
	int name;
	virtual void breathe()
	{
		cout << "Animal breathe" << endl;
	}
};

class LandAnimal : virtual public Animal {
public:
	int numLegs;
	virtual void run()
	{
		cout << "Land animal run" << endl;
	}
};

class Mammal : virtual public Animal {
public:
	int numBreasts;
	virtual void milk()
	{
		cout << "Mammal milk" << endl;
	}
};

class Human : public Mammal, public LandAnimal {
public:
	int race;
	void breathe()
	{
		cout << "Human breathe" << endl;
	}

	void milk()
	{
		cout << "Human milk" << endl;
	}

	void run()
	{
		cout << "Human run" << endl;
	}

	void eat()
	{
		cout << "Human eat" << endl;
	}
};

int main()
{
	Human human;
	
	cout << "��LandAnimalָ�����Humanʵ���ķ���" << endl;
	LandAnimal *laPtr = NULL;
	laPtr = &human;
	laPtr->run();

	cout << "��Mammalָ�����Humanʵ���ķ���" << endl;
	Mammal *mPtr = NULL;
	mPtr = &human;
	mPtr->milk();

	cout << "��Animalָ�����Humanʵ���ķ���" << endl;
	Animal *aPtr = NULL;
	aPtr = &human;
	aPtr->breathe();   //���û��ʹ����̳еĻ��˴��ᱨ����Ϊ��ΪHuman��ͬʱ�̳���LandAnimal���Mammal�ࡣ
	                   //������ж����ԣ���������֪���õ����Ǹ������е�breathe()
	return 0;
}

//һ��������̳�����һ�����࣬����������ͨ�̳�����ֱ��ӵ��һ�ݻ�����ڴ�ṹ�����Ǽ���һ�����ָ��vbptrָ������࣬����������msvc�б����ڵ�����ڴ�ռ�����
//������������������������μ̳�ʱ������Animal������Human�г���һ�Σ�����Human��������Mammal���LandAnimal�����һ�������ָ������ࡣ
//�Ӷ����������μ̳�ʱ�ĳ�ͻ��
//��ϸ��̳��ڴ�ֲ������ͣ�https://www.cnblogs.com/demian/p/6538301.html

