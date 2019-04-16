#include "stdafx.h"
#include "iostream"
using namespace std;

const int R = 5;
const int C = 5;

int maps[R][C];
int visited[R][C];

typedef struct node
{
	int x;
	int y;
	int f;

	node(int x = -1, int y = -1, int f = -1)
	{
		this->x = x;
		this->y = x;
		this->f = f;
	}
}Node;

typedef struct myqueue
{
	Node list[30];
	int head;
	int tail;

	myqueue()
	{
		head = 0;
		tail = 0;

	}
	void push(Node & n1)//�ڵ�n1���
	{
		list[tail] = n1;
		tail++;
	}

	Node getHead()//���ض��е�ͷ���
	{
		return list[head];
	}

	void pop()//����Ԫ�س���
	{
		head++;
	}
	bool isEmpty()//�����Ƿ�Ϊ�գ�����Ϊ�շ���true�����򷵻�false
	{
		if (head == tail)
			return true;
		else
			return false;
	}
}Myqueue;

bool isValied(int x, int y)//�ж���x,yΪ��������ķ����Ƿ�Ϸ�
{
	if (x >= 0 && y >= 0 && x <= 4 && y <= 4 && visited[x][y] == 0 && maps[x][y] == 0)
		return true;
	else
		return false;
}

bool equal(Node n1, Node n2)//�ж������ڵ��Ƿ���ȡ�
{
	if (n1.x == n2.x && n1.y == n2.y)
		return true;
	else
		return false;
}

int BFS(Myqueue & q, Node start, Node end)//��maps��ͼ��startΪ��ʼ�㣬endΪ��ֹ�ڵ���й������������
{                                         //�����������һ��end�ڵ��ڶ�������list�е��±ꡣ
	q.push(start);
	while (!q.isEmpty())
	{

		Node t = q.getHead();//�Ӷ�ͷȡԪ��
							 //cout<<t.x<<" "<<t.y<<endl;// 4 4
							 // Node left(t.x, t.y-1, q.head);//??
		Node left;
		left.x = t.x;
		left.y = t.y - 1;
		left.f = q.head;//��ͷԪ��Ϊ����ڵ�ĸ��ڵ㣬��ʱq.headΪ��ͷԪ����list�����е��±ꡣ

		Node right;
		right.x = t.x;
		right.y = t.y + 1;
		right.f = q.head;

		Node up;
		up.x = t.x - 1;
		up.y = t.y;
		up.f = q.head;

		Node down;
		down.x = t.x + 1;
		down.y = t.y;
		down.f = q.head;

		if (isValied(left.x, left.y))//����
		{
			visited[left.x][left.y] = 1;
			q.push(left);
			if (equal(left, end))
				return q.tail - 1;
		}
		if (isValied(up.x, up.y))
		{
			visited[up.x][up.y] = 1;
			q.push(up);
			if (equal(up, end))
				return q.tail - 1;
		}
		if (isValied(right.x, right.y))
		{
			visited[right.x][right.y] = 1;
			q.push(right);
			if (equal(right, end))
				return q.tail - 1;
		}
		if (isValied(down.x, down.y))
		{
			visited[down.x][down.y] = 1;
			q.push(down);
			if (equal(down, end))
				return q.tail - 1;
		}
		q.pop();
	}
	return -1;
}

int main()
{
	for (int i = 0; i<R; i++)
		for (int j = 0; j<C; j++)
		{
			cin >> maps[i][j];
			visited[i][j] = maps[i][j];
		}
	Myqueue q;
	Node start(4, 4, -1);//Ϊ�����·�����㣬���յ������λ�öԻ����������·��ʱ��������һ������
	Node end(0, 0, -1);

	int index = BFS(q, start, end);

	while (q.list[index].f != -1)//����-1ʱ˵���ҵ���start�ڵ㣬Ҳ���ǵ�����(4, 4)�㣬��ʱ��û����õ�
	{
		cout << "(" << q.list[index].x << ", " << q.list[index].y << ")" << endl;
		index = q.list[index].f;
	}
	cout << "(" << q.list[index].x << ", " << q.list[index].y << ")";
}
