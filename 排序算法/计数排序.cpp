#include<iostream>
#include<vector>

using namespace std;

//��������Ļ���˼��Ϊһ����������֮ǰ��ͳ����������������С��������ĸ����������ȷ���������λ�á�
//����Ҫ�������Ϊ 7 4 2 1 5 3 1 5�����7С����7����������7Ӧ��������õ����еĵڰ�λ��ͬ��3�ڵ���λ�������ظ������֣�1��1λ��2λ��������Ϊ��һ��1�ȵڶ���1С����5��1һ��λ��6λ��7λ��

//�����������ȶ���

//���������������ĸ����衣
//1 ���Ȼ��ÿ���������Ƶ��ͳ�ƣ��õ�Ԫ�ص�Ƶ�ʱ�
//2 Ȼ��Ƶ�ʱ�ת��Ϊ��Ԫ�صĿ�ʼ������
//3 ���ݸ���Ԫ�صĿ�ʼ����������ͬԪ�ط��ൽ��ʱ�����С�
//4 �����ʱ�����е�Ԫ��д�ص�ԭ�����С�
//�ο����ͣ�https://www.cnblogs.com/sun-haiyu/p/7859252.html

int  findMax(int *num, int size)
{
	int max = num[0];
	for (int i = 1; i < size; i++)
		if (num[i] > max)
			max = num[i];

	return max;
}

int findMin(int* num, int size)
{
	int min = num[0];
	for (int i = 0; i < size; i++)
		if (num[i] < min)
			min = num[i];

	return min;
}

void CountSort(int* num, int size)
{
	int max, min;
	max = findMax(num, size);
	min = findMin(num, size);
	int count_size = max - min + 1;//�����СԪ��֮�䷶Χ[min, max]�ĳ���
	vector<int> count(count_size+1,0); //����Ҫ�����鳤���϶����1����Ϊ��ͳ��ÿ��Ԫ�ص�Ƶ��ʱcount[]��ÿ��Ԫ�ؼ�ȥ��Сֵ�ټ�1��Ϊ���������count[0]��ԶҲ���ᱻ��ֵ���Ᵽ֤count[0]ʼ��Ϊ0

	//����Ƶ�ʣ�����Ҫ�����鳤���϶����1
	for (int i=0; i<size; i++)
		count[num[i] - min + 1]++;  // ʹ�ü�1������������ظ��ĸ�λ�þ�����

	//Ƶ��תԪ�صĿ�ʼ����
	for (int i = 0; i < count_size; i++)
		count[i + 1] += count[i];

	//Ԫ�ذ���ʼ�������࣬�õ�һ���ʹ�������һ������ʱ����������
	vector<int> aux(size, 0);
	for (int i = 0; i < size; i++)
		aux[count[num[i]-min]++] =  num[i]; // ���һ�����ݺ��������Ա���ͬ�����ݿ������һ����λ

	//���ݻ�д
	for (int i = 0; i < size; i++)
		num[i] = aux[i];
}

int main()
{
	int num[] = { 9, 7, 6, 3, 9, 2, 7, 3, 2, 8 };
	int size = sizeof(num) / sizeof(int);
	CountSort(num, size);

	for(int i = 0; i < size; i++)
		cout << num[i] << " ";
	cout << endl;

	return 0;
}