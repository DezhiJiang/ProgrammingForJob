#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//Ͱ�����˼�룺
//1 �������뽨���ʵ�������Ͱ��ÿ��Ͱ���Դ��ĳ����Χ�ڵ�Ԫ�أ�
//2 �������ض���Χ�ڵ�����Ԫ�ط����Ӧ��Ͱ�У�
//3 ��ÿ���ǿյ�Ͱ��Ԫ�ؽ������򣬿���ѡ��ͨ�õ����򷽷���������롢���ţ�
//4 ���ջ��ֵķ�Χ˳�򣬽�Ͱ�е�Ԫ������ȡ����������ɡ�

//ƽ��ʱ�临�Ӷ�ΪO(n)
//Ͱ����������ȶ��ġ���ȡ�������Ƕ�ÿ��Ͱ�е�Ԫ�ز�ȡ�������򷽷�������Ͱ��Ԫ�ص�����ʹ�ÿ���������ôͰ������ǲ��ȶ��ģ����ʹ�õ��ǲ�������Ͱ��������ȶ��ġ�
//Ҫע�⣺���ѡ��Ͱ�ĸ������Լ�ʹ���ĸ�ӳ�亯����Ԫ��ת����Ͱ���������ǲ�һ���ġ�

//������˵����
//Ͱ������Ϊ���鳤��
//ӳ�亯��ʹ��bucketIndex = (value * arr.length) / (maxValue + 1) ,��1��Ϊ�˱�֤���Ԫ�ؿ��Դ浽�������һ��λ��

int findMax(int *num, int size)
{
	int max = num[0];
	for (int i = 0; i < size; i++)
		if (num[i] > max)
			max = num[i];
	return max;
}

//ӳ�亯��
int toBucketIndex(int value, int maxValue, int N)
{
	return (value*N) / (maxValue + 1); //��1��Ϊ�˱�֤���Ԫ�ؿ��Դ浽�������һ��λ��
}

void BucketSort(int* num, int size)
{
	int N = size; 
	vector<vector<int>> buckets(N);

	// ����ÿ��Ԫ�ص�ֵ�����䵽��Ӧ��Χ��Ͱ��
	int max = findMax(num, size);
	for (int i = 0; i < size; i++)
	{
		int index = toBucketIndex(num[i], max, N);
		buckets[index].push_back(num[i]);
	}

	// ��ÿ���ǿյ�Ͱ���������˳�������ʱ��temp��
	vector<int> temp;
	for (int i = 0; i < N; i++)
	{
		if (buckets[i].size() != 0)
		{
			sort(buckets[i].begin(), buckets[i].end());

			for (int j = 0; j < buckets[i].size(); j++)
				temp.push_back(buckets[i][j]);
		}
	}

	// ��temp�е�����д��ԭ����
	for (int i = 0; i < temp.size(); i++)
		num[i] = temp[i];
}

int main()
{
	int num[] = { 44, 67, 32, 21, 9, 98, 44, 111, 99, 6 };
	int size = sizeof(num) / sizeof(int);
	BucketSort(num, size);
	for (int i = 0; i < size; i++)
		cout << num[i] << " ";
	cout << endl;

	return 0;
}