#include<iostream>  
#include<stack>  
using namespace std;

//ջ ����ȳ�
//��deque�ݱ����

//stack�Ļ��������У�
//1.��ջ����s.push(x);
//2.��ջ:�� s.pop().ע�⣺��ջ����ֻ��ɾ��ջ����Ԫ�أ��������ظ�Ԫ�ء�
//3.����ջ������s.top();
//4.�ж�ջ�գ���s.empty().��ջ��ʱ����true��
//5.����ջ�е�Ԫ�ظ�������s.size����;
//û�е�����

int main(void)
{
	stack<double>s;//����һ��ջ  
	for (int i = 0; i<10; i++)
		s.push(i);
	while (!s.empty())
	{
		printf("%lf\n", s.top());
		s.pop();
	}
	cout << "ջ�ڵ�Ԫ�صĸ���Ϊ��" << s.size() << endl;
	return 0;
}