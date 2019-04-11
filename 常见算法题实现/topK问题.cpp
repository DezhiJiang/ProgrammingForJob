//�ں����������ҳ�ǰ��С��5��Ԫ�غ�����5��Ԫ��

#include<iostream>
#include<queue>
#include<iterator>
#include<functional>

using namespace std;

//����n�������
vector<int> produceNumbers(int n)
{
	vector<int> data;

	int temp;
	for (int i = 0; i < n; i++)
	{
		temp = rand() % INT_MAX;
		cout << temp << " ";
		data.push_back(temp);
	}
	cout << endl;

	return data;
}
//��ӡvector
void print_vector(vector<int> data)
{
	for (int i = 0; i < data.size(); i++)
		cout << data[i] << " ";
	cout << endl;
}
//��ӡ���ȶ���
void print_priorityqueue(priority_queue<int, vector<int>, greater<int>> data)
{
	while (!data.empty())
	{
		cout << data.top() << " ";
		data.pop();
	}
	cout << endl;
}

//����һ��
//����С�����������С����ά����ǰɨ�赽�����K���������ÿһ�ε�ɨ�赽��Ԫ�أ�
//�����ڶѶ�������ѣ�Ȼ��ɾ���Ѷ�������������ֱ��ɨ��������Ԫ�ء�
//�㷨��ʱ�临�Ӷ���O(N*logK)
priority_queue<int, vector<int>, greater<int>> topK_1(int K,vector<int> data)
{
	//priority_queue<int> sort_data;
	priority_queue<int, vector<int>, greater<int>> sort_data;
	for (int i=0; i<data.size(); i++)
	{
			int temp = data[i];
		if (sort_data.size() < K || temp > sort_data.top())
			sort_data.push(temp);
		if (sort_data.size() > K)
			sort_data.pop();
	}

	return sort_data;
}

//��������
//���ÿ�������ķֻ������ҵ��ֻ�λ��K������ǰ������ݼ�Ϊ���󡣸��㷨��һ�ַǳ���Ч�Ĵ���ʽ��ʱ�临�Ӷ���O(N)
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int partition(vector<int> &arr, int low, int high)
{
	int pivotKey = arr[low];
	while (low < high)
	{
		while (low < high && arr[high] <= pivotKey)
			high--;
		swap(arr[low], arr[high]);
		while (low < high && arr[low] >= pivotKey)
			low++;
		swap(arr[low], arr[high]);
	}

	return low;
}

vector<int> topK_2(vector<int> &arr, int K)
{
	vector<int> res;
	if (K == 0)
		return res;
	if (arr.size() < K)
		return arr;
	int low = 0;
	int high = arr.size() - 1;
	int pivot = partition(arr, low, high);
	while ((pivot + 1) != K)
	{
		if ((pivot + 1) > K)
			high = pivot - 1;
		else
			low = pivot + 1;

		pivot = partition(arr, low, high);
	}

	for (int i = 0; i < K; i++)
		res.push_back(arr[i]);

	return res;
}

int main()
{
	vector<int> data;
	priority_queue<int, vector<int>, greater<int>> res1;   //С����
	vector<int> res2;
	data = produceNumbers(10);
	res1 = topK_1(3, data);
	print_priorityqueue(res1);

	res2 = topK_2(data, 3);
	print_vector(res2);

	return 0;
}