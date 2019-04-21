#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

//����ģʽ
//����ʽ���ڵ�һ���õ���ʵ����ʱ��Ż�ȥʵ����
//����ʽ���ڵ����ඨ���ʱ��ͽ���ʵ����

//����Ҫ�����߳�ͬ���������ڷ������Ƚϴ󣬻��߿��ܷ��ʵ��̱߳Ƚ϶�ʱ�����ö���ʵ�֣�����ʵ�ָ��õ����ܡ������Կռ任ʱ�䡣
//�ڷ�������Сʱ����������ʵ�֣�������ʱ�任�ռ�

//����ʽ
class Singleton1
{
public:
	static Singleton1* getInstance();
private:
	Singleton1() {};
	//�Ѹ��ƹ��캯����=������Ҳ��Ϊ˽�У���ֹ������
	Singleton1(const Singleton1&) {}; 
	Singleton1& operator=(const Singleton1&) {};

	static Singleton1* instance;

};

Singleton1* Singleton1::instance = new Singleton1();

Singleton1* Singleton1::getInstance()
{
	return instance;
}

//�����ľ�������ʵ��
class Singleton2
{
public:
	static mutex sig_mutex;
	static Singleton2* getInstance();

private:
	static Singleton2* instance;

	Singleton2() {};
	//�Ѹ��ƹ��캯����=������Ҳ��Ϊ˽�У���ֹ������
	Singleton2(const Singleton2&) {};
	Singleton2& operator=(const Singleton2&) {};

};

mutex Singleton2::sig_mutex;
Singleton2* Singleton2::instance = nullptr;
Singleton2* Singleton2::getInstance()
{
	unique_lock<mutex> ulock(sig_mutex);
	ulock.lock();
	if (instance == nullptr)
		instance = new Singleton2();
	ulock.unlock();

	return instance;
}

//�ڲ���̬����������ʵ��
class Singleton3
{
public:
	static mutex sig_mutex;
	static Singleton3* getInstance();
private:
	Singleton3() {};
	//�Ѹ��ƹ��캯����=������Ҳ��Ϊ˽�У���ֹ������
	Singleton3(const Singleton3&) {};
	Singleton3& operator=(const Singleton3&) {};
};
mutex Singleton3::sig_mutex;
Singleton3* Singleton3::getInstance()
{
	unique_lock<mutex> ulock(sig_mutex);
	ulock.lock();
	static Singleton3 instance;
	ulock.unlock();

	return &instance;
}

int main()
{
	Singleton1* singleton1_1 = Singleton1::getInstance();
	Singleton1* singleton1_2 = Singleton1::getInstance();

	if (singleton1_1 == singleton1_2)
		cout << "singleton1_1 = singleton1_2" << endl;

	//Singleton2* singleton2_1 = Singleton2::getInstance();
	//Singleton2* singleton2_2 = Singleton2::getInstance();

	//if (singleton2_1 == singleton2_2)
	//	cout << "singleton2_1 = singleton2_2" << endl;

	Singleton3* singleton3_1 = Singleton3::getInstance();
	Singleton3* singleton3_2 = Singleton3::getInstance();

	if (singleton3_1 == singleton3_2)
		cout << "singleton3_1 = singleton3_2" << endl;



	return 0;
}