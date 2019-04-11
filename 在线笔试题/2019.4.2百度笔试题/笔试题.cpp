#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


//�ٶȱ�����1 �������
// 0 <=count<= 1000
//ȫ����˼����
//��������1�� �Ƿ���Ҫ����
int isswap(string arr, int from, int to, int count)
{
	//���Ҫ��������to�ַ���from�ַ���ǰcountλ�ڳ��ֹ����򲻽���
	if (from > 0)
	{
		int j = 0;
		for (int i = 1; i <= count; i++)
		{
			j = from - i;
			if (j < 0)
				break;
			if (arr[j] == arr[to])
				return 0;
		}
	}

	for (int i = from; i < to; i++)
	{
		if (arr[i] == arr[to])
			return 0;
	}

	return 1;
}
//��������2: ����
void swap(char *a, char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
//��������3: vector<char> תstring
string combine(vector<char> res)
{
	string str = "";
	for (int i = 0; i < res.size(); i++)
		str += res[i];
	return str;
}
//��������4�����ظ�ȫ����
void permutations(string arr, int k, int n, vector<vector<char>> *all_res,int count)
{
	//vector<vector<char>> all_res;
	if(k == n)
	{
		vector<char> one_res;
		one_res.clear();
		for (int i = 0; i < n; i++)
		{
			one_res.push_back(arr[i]);
		}
		all_res->push_back(one_res);
	}else{
		for (int i = k; i < n; i++)
		{
			if (isswap(arr, k, i,count))
			{
				swap(&arr[k], &arr[i]);
				permutations(arr, k + 1, n,all_res,count);
				swap(&arr[i], &arr[k]);
			}
		}
	}

}
//��������5�����н����������ȫ���еó��ֵ�����С�Ľ��
string getMinResult(string students, int count)
{
	vector<vector<char>> *res = new vector<vector<char>>();

	permutations(students, 0, students.size(), res, count);

	//��ӡȫ���еĽ��
	//for (int i = 0; i < res->size(); i++)
	//{
	//	string temp = combine(res->at(i));
	//	cout << temp << endl;
	//}

	sort(res->begin(), res->end());
	string str = combine(res->at(0));
	return str;
}
//��������6�� �Ƚ���
typedef pair<char, int> PAIR;
bool cmp_by_value(const PAIR& lhs, const PAIR& rhs)
{
	return lhs.second > rhs.second;
}
//���ĺ���
string rearrange(string students, int count)
{
	//�ж��ܲ����ţ��ж����ݣ����������İ༶������*count С������༶�����������������
	                        //���򷵻� -1
	map<char, int> mymap;
	for (int i = 0; i < students.size(); i++)
		mymap[students[i]]++;
	
	vector<PAIR> sort_mymap(mymap.begin(), mymap.end());
	sort(sort_mymap.begin(), sort_mymap.end(), cmp_by_value); //����ѧ�����԰༶��������
	
	//ͳ�Ƴ��������༶��������༶��������
	int stu_count = 0;	
	for (int i = 1; i < sort_mymap.size(); i++)
	{
		stu_count = stu_count + sort_mymap[i].second;
	}
	
	if ((sort_mymap[0].second - 1) * count > stu_count)
		return "-1";

	//����������У�������ȫ����������
	string res = getMinResult(students, count);
	return res;
}
int main()
{
	string str = "ddgdghghh";
	string str1 = "ddddghghh";
	string res = rearrange(str1, 2);

	cout << res << endl;
	system("pause");

	return 0;

}

////�ٶ�4-2������2
//int maxNormalTemp(int size, int allowedChanges, string reading)
//{
//	//�������ڣ��޶�һ������������ֻ�ܺ���K��0�����������K�����ƶ���ˣ������в���ȡ�������ֵ
//	int left = 0, right = 0;  //�������ڵ���߽���ұ߽�
//	int max_size = 0;         //����������Ԫ�ص����ֵ
//	int count_0 = 0;          //���������ڵ�0����
//	int count_1 = 1;          //���������ڵ�1����
//
//	//ȷ���ʼ�������ڵ����ұ߽�
//	for (int i = 0; i < size; i++)
//	{
//		if (reading[i] == '0')
//			count_0++;
//		if (reading[i] == '1')
//			count_1++;
//		if (count_0 == allowedChanges)
//		{
//			right = i;
//			max_size = right - left + 1;  //1�����ֵ���ǻ��������ڵ�Ԫ�ش�С
//			break;
//		}
//	}
//
//	for (int i = right+1; i < size; i++)
//	{
//		right = i;     //�ƶ��������ڵ��Ҷ�
//		if (reading[i] == '0')
//		{
//			//��Ҫ�ƶ��������ڵ����
//			while (reading[left] != '0')    //�ƶ��������ڵ���ˣ�ֱ����
//				left++;
//			left++;  //ȷ���µ���߽�
//
//		}
//			
//		if (reading[i] == '1')
//		{
//			//����Ҫ�ƶ���ˣ�ֻ��Ҫ�ƶ��Ҷ�
//			if ((right - left + 1) > max_size)
//				max_size = right - left + 1;
//		}
//	}
//	return max_size;
//}
//
//int main()
//{
//	string str = "1010101";
//	int size = str.size();
//	cout << size << endl;
//	int allowed = 2;
//	int max_count_1 = maxNormalTemp(size, allowed, str);
//	cout << "res : " << max_count_1 << endl;
//
//	return 0;
//}


////�ٶ�4-2������3
////��̰��˼������ÿ���ҳ�����������ˣ��������һ����Ŀ

////��������1������һ������������ֵ���Ԫ�ص��±�
//int indexOfMax(int num, int* arr)
//{
//	int index = 0;
//	int max = arr[0];
//	for (int i = 1; i < num; i++)
//	{
//		if (arr[i] > max)
//			index = i;
//	}
//	return index;
//}
////��������2���������˽��м���
//void decreaseScore(int num, int projCmptDec, int restDec, int* errorScore, int index)
//{
//	for (int i = 0; i < num; i++)
//	{
//		if (errorScore[i] == 0)
//			continue;
//
//		if (i == index)
//			errorScore[i] -= projCmptDec;
//		else
//			errorScore[i] -= restDec;
//
//		if (errorScore < 0)
//			errorScore[i] = 0;
//	}
//
//	return;
//}
////���ĺ���
//int minNumberOfProjects(int num, int projCmptDec, int restDec, int* errorScore)
//{
//	int res = 0;   //��С��Ŀ��
//	int index_max;
//	index_max = indexOfMax(num, errorScore);
//
//	while (errorScore[index_max] != 0)
//	{
//		res++;   //�ô���������������һ����Ŀ
//		decreaseScore(num, projCmptDec, restDec, errorScore, index_max);
//
//		index_max = indexOfMax(num, errorScore);
//	}
//
//	return res;
//}
//
//int main()
//{
//	int num = 4;
//	int projDec = 3;
//	int restDec = 1;
//	int errorScore[] = { 9,8,2,5 };
//
//	int min_proj = minNumberOfProjects(num, projDec, restDec, errorScore);
//
//	cout << "min_proj = " << min_proj << endl;
//
//	return 0;
//}