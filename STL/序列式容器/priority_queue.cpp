#include<iostream>
#include <queue>
#include<functional>
using namespace std;

//���ȶ��о��ж��е��������ԣ���������������ֻ�����������������ڲ���һ��������������һ����ʵ�ֵ�
//�Ͷ��л���������ͬ:

//top ���ʶ�ͷԪ��
//empty �����Ƿ�Ϊ��
//size ���ض�����Ԫ�ظ���
//push ����Ԫ�ص���β(������)
//emplace ԭ�ع���һ��Ԫ�ز��������
//pop ������ͷԪ��
//swap ��������


int main()
{
	//���ڻ������� Ĭ���Ǵ󶥶�
	priority_queue<int> a;
	//��ͬ�� priority_queue<int, vector<int>, less<int> > a;

	//             ����һ��Ҫ�пո񣬲�Ȼ���������������
	priority_queue<int, vector<int>, greater<int> > c;  //��������С����
	priority_queue<string> b;

	for (int i = 0; i < 5; i++)
	{
		a.push(i);
		c.push(i);
	}
	while (!a.empty())
	{
		cout << a.top() << ' ';
		a.pop();
	}
	cout << endl;

	while (!c.empty())
	{
		cout << c.top() << ' ';
		c.pop();
	}
	cout << endl;

	b.push("abc");
	b.push("abcd");
	b.push("cbd");
	while (!b.empty())
	{
		cout << b.top() << ' ';
		b.pop();
	}
	cout << endl;
	return 0;
}
