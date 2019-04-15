#include<iostream>
#include<list>
#include<algorithm>

//˫������
//�������ռ䣬�����ɾ��Ԫ����Զ�ǳ���ʱ��

using namespace std;

void printf(list<int> list)
{
	for (auto it = list.begin(); it != list.end(); it++)
		cout << *it << " ";
	cout << endl;
}
// a predicate implemented as a function:
bool single_digit(const int& value) 
{ 
	return (value < 10); 
}

// a predicate implemented as a class:
struct is_odd {
	//���ز����� ()
	bool operator() (const int& value) { return (value % 2) == 1; }
};


int main()
{
	int num[] = { 11,5,6,7,8,9 };
	list<int> list2(num, num + 6);

	auto ite = find(list2.begin(), list2.end(), 5); //��findʧ�ܣ��᷵��end()������

	//����͵�����˫����ɣ�
	list2.push_front(1);  //��ǰ�����Ԫ��
	list2.push_back(3);   //�Ӻ������Ԫ��
	list2.pop_front();
	list2.pop_back();

	//��ȡԪ��
	list2.front();
	list2.back();

	list<int> list3(3, 1);
	list2.splice(ite, list3); //��list3ƴ�ӵ�ite��ָ��λ��֮ǰ
	printf(list2);
	list2.reverse();  //��list��ת
	printf(list2);
	list2.sort();     //listֻ��ʹ���Դ���sort(),������STL��sort()����,��Ϊsort��Ҫ��������������ʵ�����
	printf(list2);
	list2.unique();   //�޳�����Ԫ�ؼ���ظ�Ԫ��
	printf(list2);  
	list2.remove(5);  //ɾ��list���ض���ֵ
	printf(list2);

	//������ɾ��
	list2.remove_if(single_digit);           // �Ƴ�С��10��Ԫ��
	list2.remove_if(is_odd());               // �Ƴ�����

	//�ϲ������list
	list<int> first, second;

	first.push_back(3);
	first.push_back(2);
	first.push_back(9);
	
	second.push_back(7);
	second.push_back(1);
	second.push_back(4);
	
    first.sort();
	second.sort();
	
	first.merge(second);
	printf(first);

	first.swap(second);  //��������list������
	first.resize(8);     //����list��С
	first.clear();       //���

	//����̬�������ռ�
	list<int> mylist;
	int * p;
	
    // allocate an array of 5 elements using mylist's allocator:
	p = mylist.get_allocator().allocate(5); //get_allocator  //����һ������list�йصķ���������
}