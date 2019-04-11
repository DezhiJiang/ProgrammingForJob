//����Ҫ��
//1�����߳������ߡ����߳�������
//2�������г���>100ʱ��������ֹͣ����������<20��������ֹͣ����
//3���ʵ���һЩprint����֤��ĳ��򣬲�Ȼ�������������������ǲ�֪��������ʲô�����

#include<iostream>
#include<queue>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<functional>

using namespace std;

queue<int> q;
mutex m;
condition_variable cv1;  //for 100
condition_variable cv2;  //for 20
bool sig = false;

int count_p = 0;     //�����߼���
int count_c = 0;     //�����߼���

void produce(int x)
{
	unique_lock<mutex> lock(m);

	//ѭ�����
	while (q.size() > 100)
	{
		cv1.wait(lock);
	}
	//���С��100
	q.push(x);
	count_p++;
	cout << "produce:" << x << " "<< count_p << endl;
	if (q.size() >= 20)
		cv2.notify_all();
}

void consume()
{
	unique_lock<mutex> lock(m);
	while (q.size() < 20)
	{
		cv2.wait(lock);
	}

	count_c--;
	cout << "consume:" << q.front() <<" "<< count_c << endl;
	q.pop();
	if (q.size() < 100)
		cv1.notify_all();
}

int main()
{
	thread producers[200];
	for (int i = 0; i < 200; i++)
		producers[i] = thread(produce, i);

	thread consumers[200];
	for (int i = 0; i < 200; i++)
		consumers[i] = thread(consume);

	for (auto& p : producers)
		p.join();
	for (auto& c : consumers)
		c.join();

	//���յ����������� �����߻����200�����������߻�������181������ֻʣ19��<20����������ֹͣ����

	return 0;
}
