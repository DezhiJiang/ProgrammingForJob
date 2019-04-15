//����������1������
//˼·�� �Ը��ڵ��������������ڵ���������������������������ʱ��

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//���ڵ�ṹ��
struct Node 
{
	int value;            //���ڵ����λ��
	vector<int> childs;   //�뱾�ڵ�ֱ�������Ľڵ�

	Node(int x) //���캯��
	{ 
		this->value = x;

	}  
};

//��unBL �ߺ��Ժ�node[i]�ڵ���ͨ�Ľڵ���
int getNodeEdge(vector<Node*> nodes, int i, int unBL)
{
	int count = 0;
	vector<int> integers = nodes[i]->childs;
	count += integers.size() - 1;
	for (auto item : integers)
	{
		if (item == unBL)
			continue;
		count += getNodeEdge(nodes, item, nodes[i]->value);
	}

	return count;
}

int main()
{
	int n;
	cin >> n;    //���ڵ���

	vector<Node*> nodes;
	for (int i = 0; i <= n; i++)
	{
		Node *node = new Node(i);
		nodes.push_back(node);
	}
	int a, b;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b;
		nodes[a]->childs.push_back(b);
		nodes[b]->childs.push_back(a);
	}

	int max_nodes = 0;
	vector<int> intergers = nodes[1]->childs;
	for (auto item : intergers)
	{
		int count = getNodeEdge(nodes, item, 1);
		max_nodes = max(count, max_nodes);
	}

	int res = max_nodes + 1;
	cout << "res = " << res << endl;

	return 0;
}