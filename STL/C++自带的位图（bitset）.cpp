#include<iostream>
#include<bitset>  //C++�Դ���bitset
#include<string>

using namespace std;

int main()
{
	//������ʽ
	bitset<10> num;           //����һ��λͼ������ָ��λͼ�Ĵ�С��Ĭ��ÿһλ��Ϊ0
	bitset<4> foo(string("0001"));

	//λ��ȡ����
	num[3] = 1;               //���ò�����ֱ�Ӹ�ֵ
	num[4] = num[3];          //ֱ�ӿ���
	cout << num << endl;
	int count = num.count();   //����count()������ȡλͼ��1�ĸ���
	cout << "count of 1 = " << count << endl;
	int size = num.size();     //����size()������ȡλͼ�Ĵ�С
	cout << "size of num = " << size << endl;
	int test = num.test(4);    //����test()������ȡλͼ�е�4λ��ֵ��0��1��
	cout << "value of 4 = " << test << endl;
	bool any = num.any();      //����any()������ȡnum�е��Ƿ���λ������
	cout << "any = " << any << endl;
	bool none = num.none();    //����none()������ȡnum���Ƿ�����λ��û������
	cout << "none = " << none << endl;
	bool all = num.all();      //����all()������ȡnum�е��Ƿ�����λ��������
	cout << "all = " << all << endl;

	//λ��������
	num.set(2);     //��λͼ�еڶ�λ����Ϊ1
	cout << "num[2]= " << num.test(2) << endl;
	num.reset(2);   //��λͼ�еڶ�λ����Ϊ0
	cout << "num[2]= " << num.test(2) << endl;
	num.flip(9);   //�� 2+1 λȡ���� ע��𳬹�λͼ��С
	cout << num << endl;

	//λͼ��������
	string s = num.to_string();
	cout << s << endl;
	unsigned long ul = num.to_ulong();
	cout << ul << endl;
	unsigned long long ull = num.to_ullong();
	cout << ull << endl;

	return 0;
}