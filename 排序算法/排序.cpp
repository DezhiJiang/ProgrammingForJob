#include<iostream>

using namespace std;

//ע�����ļ��µ�������������������δ�ں�����ͷ���в����쳣�жϣ�ʵ����Ӧ��ӽ�ȥ

//�����㷨���ࣺ��1����������ֱ�Ӳ�������        �ȶ�   ʱ�䣺n n^2 n^2         �ռ䣺1
                             //ϣ����shell������   ���ȶ� ʱ�䣺n n^1.5 n^2       �ռ䣺1
              //��2��ѡ������ֱ��ѡ������        ���ȶ� ʱ�䣺n^2 n^2 n^2       �ռ䣺1
                             //������              ���ȶ� ʱ�䣺nlogn nlogn nlogn �ռ䣺1
              //��3����������ð������            �ȶ�   ʱ�䣺n n^2 n^2         �ռ䣺1
                             //��������            ���ȶ� ʱ�䣺nlogn nlogn n^2   �ռ䣺nlogn
              //��4���鲢����                      �ȶ�   ʱ�䣺nlogn nlogn nlogn �ռ䣺n

//���Ժ��壺�ȶ��� ����ʱ�临�Ӷ� ƽ��ʱ�临�Ӷ� �ʱ�临�Ӷ� �ռ临�Ӷ�

//����������
void swap(int& a, int& b)
{
	int temp = b;
	b = a;
	a = temp;
}

//ð������
//˼�룺1���Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�������������
      //2����ÿһ������Ԫ����ͬ���Ĺ������ӿ�ʼ��һ�Ե���β�����һ�ԡ�����һ�㣬����Ԫ��Ӧ�û�����������
      //3��������е�Ԫ���ظ����ϵĲ��裬�������һ����
      //4������ÿ�ζ�Խ��Խ�ٵ�Ԫ���ظ�����Ĳ��裬ֱ��û���κ�һ��������Ҫ�Ƚϡ�
//���ԣ��ȶ� ʱ�䣺n n^2 n^2 �ռ䣺1
void Bubble_Sort(int *list, int count)
{
	int end;
	for (int i = 0; i < count-1 ; ++i) {
		end = count - 1 - i;
		for (int j = 0; j < end; ++j)
			if (list[j] > list[j + 1])  //��Ϊ�������j+1,�����ж�����Ϊcount-1
				swap(list[j], list[j + 1]);
	}
}
//ð��������Ż��汾������汾��������ð�������������ʱ�临�Ӷ�Ϊo(n)
void Bubble_Sort_Plus(int *list, int count)
{
	bool didSwap;  //��������Ƿ��н��й���������
	int end;
	for (int i = 0; i < count - 1; i++) {
		didSwap = false;
		end = count - 1 - i;
		for (int j = 0; j < end; ++j)
		{
			if (list[j] > list[j + 1]) {
				swap(list[j], list[j + 1]);
				didSwap = true;
			}
		}
		//���û�н��й�����������˵��˳���Ѿ����ź��˵�
		if (didSwap == false)
			return;
	}

}

//ֱ��ѡ������
//˼�룺��һ�δ�R[0]~R[n-1]��ѡȡ��Сֵ����R[0]������
      //�ڶ��δ�R[1]~R[n-1]��ѡȡ��Сֵ����R[1]������....��
      //��i�δ�R[i-1]~R[n-1]��ѡȡ��Сֵ����R[i-1]������.....��
      //��n-1�δ�R[n-2]~R[n-1]��ѡȡ��Сֵ����R[n-2]�������ܹ�ͨ��n-1�Σ�
      //�õ�һ�����������С�������е���������
//���ԣ� ���ȶ� ʱ�䣺n^2 n^2 n^2 �ռ䣺1
void Select_Sort(int *list, int count)
{
	int min;
	for (int i = 0; i < count-1; i++)
	{
		min = i;
		for (int j = i + 1; j < count; j++)
		{
			if (list[min] > list[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(list[i], list[min]);
		}
	}
}

//ֱ�Ӳ�������
//˼�룺��n���������Ԫ�ؿ���һ��������һ���������ʼʱ�������ֻ��һ��Ԫ�أ����������n-1��Ԫ�أ�
      //������̼�ÿ�δ��������ȡ����һ��Ԫ�أ��������뵽������У�ʹ֮��Ϊ�µ�������ظ�n-1���������������̡�
//���ԣ��ȶ� ʱ�䣺n n^2 n^2 �ռ䣺1
void Insert_Sort(int *list, int count)
{
	int temp; //�˴��䵱�ڱ�������list���������ռһ����λ
	int i, j;
	//��һ��forѭ���Դӵڶ�����ʼ�����е����ֱ�����
	//Ƕ�׵�forѭ����ÿ�α�������ʱ��ȡ��������һ��Ԫ������������Ԫ�رȽϣ�
	//�������������ҪС�򽻻���ֱ�����ʵ�λ��
	for (i = 1; i < count; i++)
	{
		temp = list[i];  //����������ȡһ��Ԫ��
		//����Ԫ�ز��뵽����������ȷλ��
		for (j = i - 1; list[j] > temp&&j >= 0; j--)
		{
			list[j + 1] = list[j];  //ֻҪû�ҵ����ʵĲ���λ�ã��ͽ�������е�Ԫ������������һλ
		}
		list[j + 1] = temp;
	}
}
//ֱ�Ӳ����������һ��ʵ��
void Insert_Sort_Plus(int *list, int count)
{
	for (int i = 1; i < count; ++i)
	{
		for (int j = i; j > 0; --j)  //ȡ�������ĵ�һ��Ԫ����������Ԫ�ؽ��бȽ�
		{
			if (list[j] < list[j - 1])
				swap(list[j], list[j - 1]);
		}
	}
}

//ϣ����shell������
//˼�룺��1��ϣ������shell sort��������򷽷��ֳ�Ϊ��С����������1959��D��L��Shell������ġ��÷����Ļ���˼���ǣ�
           //�������Ԫ��������n��Ԫ�أ�����ȡһ������increment��С��n����Ϊ�����ȫ��Ԫ�ط�Ϊincrement�������У�
           //���о���Ϊincrement��Ԫ�ط���ͬһ���������У���ÿһ���������зֱ�ʵ��ֱ�Ӳ�������
           //Ȼ����С���increment���ظ����������л��ֺ���������
           //ֱ�����ȡincrement = 1��������Ԫ�ط���ͬһ��������������Ϊֹ��
      //��2�����ڿ�ʼʱ��increment��ȡֵ�ϴ�ÿ���������е�Ԫ�ؽ��٣������ٶȽϿ죬���������incrementȡֵ�𽥱�С��
           //��������Ԫ�ظ��������࣬������ǰ�湤���Ļ����������Ԫ���Ѿ������������������ٶ���Ȼ�ܿ졣

//���ԣ����ȶ� ʱ�䣺n n^1.5 n^2 �ռ䣺1
void Shell_Sort(int *list, int count)
{
	int i, j;
	int temp;
	int increment = count;

	do {
		increment = increment / 3 + 1;    //��������
		for (i = increment; i < count; i++)   //��ÿ�����ֽ���ֱ�Ӳ�������
		{
			if (list[i] < list[i - increment])//��������ȡһ��Ԫ�أ����뵽��Ӧ�������еĺ���λ��
			{
				temp = list[i];
				for (j = i - increment; j >=0 && list[j] > temp; j -= increment)
				{
					list[j + increment] = list[j];
				}
				list[j + increment] = temp;
			}
		}
	} while (increment > 1);
}

//�����򣨴󶥶ѣ�
//�ο����ͣ�https://www.cnblogs.com/0zcl/p/6737944.html
//�󶥶Ѹ���ѷ�Ϊ���Ѻ���С�ѣ���ʵ������ȫ��������
            //����Ҫ��ڵ��Ԫ�ض�Ҫ��С���亢�ӣ���С��Ҫ��ڵ�Ԫ�ض������������Һ��ӣ�
            //���߶����Һ��ӵĴ�С��ϵ�����κ�Ҫ����ʵ�ܺ���⡣
            //��������Ķ��壬���ǿ��Ե�֪���������ѵĸ��ڵ��Ԫ��һ����������е����ֵ��
//˼�룺1.����ʼ������ؼ�������(R1,R2....Rn)�����ɴ󶥶ѣ��˶�Ϊ��ʼ��������
      //2.���Ѷ�Ԫ��R[1]�����һ��Ԫ��R[n]��������ʱ�õ��µ�������(R1, R2, ......Rn - 1)���µ�������(Rn)
      //3.���ڽ������µĶѶ�R[1]����Υ���ѵ����ʣ������Ҫ�Ե�ǰ������(R1, R2, ......Rn - 1)����Ϊ�¶ѣ�
        //Ȼ���ٴν�R[1]�����������һ��Ԫ�ؽ������õ��µ�������(R1, R2....Rn - 2)���µ�������(Rn - 1, Rn)��
        //�����ظ��˹���ֱ����������Ԫ�ظ���Ϊn - 1������������������
//����˼�룺ÿ�ζ�ȡ�Ѷ���Ԫ�أ����������������棬Ȼ��ʣ���Ԫ�����µ���Ϊ���ѣ��������ƣ����յõ���������С�
//���ԣ����ȶ� ʱ�䣺nlogn nlogn nlogn �ռ䣺1
void Heap_Adjust(int *list, int s, int m)      //����Ϊһ����
{
	int temp = list[s];
	for (int j = 2 * s + 1; j <= m; j = 2 * j + 1)
	{
		if (list[j] < list[j + 1] && j < m)   //������ӽڵ�С�����ӽڵ㣬��Ŀ��ڵ㶨Ϊ���ӽڵ�
		{
			j++;
		}
		if (temp > list[j]) //����ǰ�ĶѶ�Ԫ�������ӽڵ��нϴ��ֵ���бȽϣ������ڵ��ֵ�������Һ��ӽڵ��ֵ����ѭ������
			break;          //��Ϊÿ�ε����ѵ�ԭ��ֻ��ԭ�ȵĸ��ڵ������������һ���ڵ㽻���˶��ѣ��������ֶ��������������
		list[s] = list[j];  //���ϴ�ֵ�������ڵ㴦
		s = j;     //���˴νڵ㽻����Ժ��沿�ֵĶ������Ƿ�������ƻ� 
	}
	list[s] = temp;
}
void Heap_Sort(int *list, int len)
{
	//�������鹹�����ѣ������ӽڵ�=���ڵ�*2+1��
	//�ȶ�ǰ�벿�ֽ��е����ҳ����㣬Ȼ�����������β���ҳ�����
	
	//����һ���󶥶�
	for (int s = len / 2 - 1; s >= 0; s--)
	{
		Heap_Adjust(list, s, len - 1);
	}

	//����
	for (int i = len - 1; i >= 1; i--)
	{
		swap(list[0], list[i]);
		Heap_Adjust(list, 0, i - 1);
	}
}

//�鲢����
//˼�룺�ǽ����ڹ鲢�����ϵ�һ����Ч�������㷨,���㷨�ǲ��÷��η���һ���ǳ����͵�Ӧ�á�
      //��������������кϲ����õ���ȫ��������У�����ʹÿ��������������ʹ�����жμ�����
      //�������������ϲ���һ���������Ϊ��·�鲢��
//�鲢�����Ĺ���ԭ�����£�
      //��һ��������ռ䣬ʹ���СΪ�����Ѿ���������֮�ͣ��ÿռ�������źϲ��������
      //�ڶ������趨����ָ�룬���λ�÷ֱ�Ϊ�����Ѿ��������е���ʼλ��
      //���������Ƚ�����ָ����ָ���Ԫ�أ�ѡ�����С��Ԫ�ط��뵽�ϲ��ռ䣬���ƶ�ָ�뵽��һλ��
      //�ظ�����3ֱ��ĳһָ�볬������β
      //����һ����ʣ�µ�����Ԫ��ֱ�Ӹ��Ƶ��ϲ�����β
//���ԣ��ȶ� ʱ�䣺nlogn nlogn nlogn �ռ䣺n
//��������¹鲢����Ŀռ临�Ӷ�ΪO(n),�����������ռ临�Ӷ�ΪO(1),�������Ļ�ʱ�临�ӶȽ�����O��n^2��
void Merge(int *list,int *reg, int start, int end)
{
	if (start >= end)
		return;
	int mid = start + (end - start) / 2;
	int i, j, k;
	i = start;
	j = mid +1;
	k = 0;

	while (i <= mid&&j <= end)
	{
		if (list[i] <= list[j])
			reg[k++] = list[i++];
		else
			reg[k++] = list[j++];
	}

	while (i <= mid)
		reg[k++] = list[i++];
	while (j <= end)
		reg[k++] = list[j++];

	for (int i = 0; i < k; i++)
		list[start + i] = reg[i];
}
void MSort(int *list, int *reg, int start, int end)
{
	if (start < end)
	{
		int mid = start + (end - start ) / 2;   //�������int
		MSort(list, reg, start, mid);           //����߽�������
		MSort(list, reg, mid + 1, end);         //���ұ߽�������
		Merge(list, reg, start, end);           //������õ����ݺϲ�
	}
}
void Merge_Sort(int *list, int count)
{
	int *reg = new int[count];
	MSort(list,reg, 0, count - 1);
	delete[] reg;
}

//��������
//˼�룺ͨ��һ������Ҫ��������ݷָ�ɶ����������֣�����һ���ֵ��������ݶ�������һ���ֵ��������ݶ�ҪС��
      //Ȼ���ٰ��˷����������������ݷֱ���п�����������������̿��Եݹ���У��Դ˴ﵽ�������ݱ���������С�
      //ʵ�ֿ��������㷨�Ĺؼ���������������ѡ��һ�����֣����������������е����ֳַ��������֣�
      //��ѡ������С�������Ƶ��������ߣ���ѡ�����ִ�������Ƶ�������ұ�
//���ԣ����ȶ� ʱ�䣺nlogn nlogn n^2 �ռ䣺nlogn
int Partition(int *list, int low, int high)
{
	int pivotKey;   //���ĵ�
	pivotKey = list[low];
	while (low < high)
	{
		while (low < high&&list[high] >= pivotKey)
		{
			high--;
		}
		swap(list[low], list[high]);  //��pivotKey�ƶ����Ӻ���ǰ��һ������С��λ�ã���ʱhigh���������Ԫ�ض�����pivotKey
		while (low < high&&list[low] <= pivotKey)
		{
			low++;
		}
		swap(list[low], list[high]);  //��pivotKey�ƶ�����ǰ�����һ���������λ�ã���ʱlowǰ�������Ԫ�ض�С��pivotKey

		//ÿһ��ѭ����������low��high֮��ķ�Χ��С��ֱ��low>=high,pivotKey��ɸѡ�������
	}
	return low;  //�������ĵ������ƶ�����λ��

}
void QSort(int *list, int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition(list, low, high);
		QSort(list, low, pivot - 1);
		QSort(list, pivot + 1, high);
	}
}
void Quick_Sort(int *list, int count)
{
	QSort(list, 0, count - 1);
}

int main()
{
	//��������1
	int TestData1[] = { 11,2,5,4,1,3,9,7,8,6,11,10 };
	int count1 = sizeof(TestData1) / sizeof(int);

	//��������2
	int TestData2[] = { 88, 4419, 10584, 452, 996650, 6754, 957, 239, 91700, 9405,
		                8560, 807347, 20205, 957730, 195132, 171, 45249, 729108, 
		                856, 6264, 713998, 558, 2726, 17671, 39225, 333, 27534, 79588, 
		                19111, 62133, 314, 296433, 940, 19684, 222752, 741, 7009, 7240,
		                49455, 9348, 103829, 384565, 1749, 177, 497, 3953, 649, 46593, 
		                2630, 245, 270603, 297637, 99204, 99867, 89431, 3986, 99454,
		                8089, 934666, 434, 983492, 39929, 6769, 955109, 65704, 18568,
		                76695, 6435, 5578, 744, 13680, 139812, 775563, 93104, 99663, 
		                322628, 6592, 12941, 403547, 619774, 5506, 1515, 72955, 9755,
		                728165, 78168, 1485, 94370, 7373};
	int count2 = sizeof(TestData2) / sizeof(int);

	////ð���������
	//Bubble_Sort(TestData1, count1);
	//Bubble_Sort(TestData2, count2);
	////�Ż����ð���������
	//Bubble_Sort_Plus(TestData1, count1);
	//Bubble_Sort_Plus(TestData2, count2);

	////ֱ��ѡ���������
	//Select_Sort(TestData1, count1);
	//Select_Sort(TestData2, count2);

	////ֱ�Ӳ�������ʵ��һ����
	//Insert_Sort(TestData1, count1);
	//Insert_Sort(TestData2, count2);
	////ֱ�Ӳ�������ʵ�ֶ�����
	//Insert_Sort_Plus(TestData1, count1);
	//Insert_Sort_Plus(TestData2, count2);

	////ϣ�����������
	//Shell_Sort(TestData1, count1);
	//Shell_Sort(TestData2, count2);

	////���������
	//Heap_Sort(TestData1, count1);
	//Heap_Sort(TestData2, count2);

	//�鲢�������
	Merge_Sort(TestData1, count1);
	Merge_Sort(TestData2, count2);

	////�����������
	//Quick_Sort(TestData1, count1);
	//Quick_Sort(TestData2, count2);

	//��ӡ��������1����������
	cout << "TestData1 result: " << endl;
	for (int i = 0; i < count1; ++i)
		cout << TestData1[i] << " ";
	cout << endl;

	//��ӡ��������2����������
	cout << "TestData2 result: " << endl;
	for (int i = 0; i < count2; ++i)
		cout << TestData2[i] << " ";
	cout << endl;

	//��ֹ��������
	int rest;
	cin >> rest;
	return 0;
}