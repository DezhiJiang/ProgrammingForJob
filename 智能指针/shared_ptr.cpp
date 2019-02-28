#include<iostream>
#include<memory>

/* 
 * shared_ptr ����ʹ�ö�������ü�������1����ֵʹ��ԭ�������ü�����1
 */

int main()
{
	{
		int a = 10;
		std::shared_ptr<int> ptra = std::make_shared<int>(a);
		std::shared_ptr<int> ptra2(ptra);  //���������ü�����һ
		std::cout << ptra.use_count() << std::endl;  //2

		int b = 20;
		int *pb = &a;
		//	std::shared_ptr<int> ptrb = pb;  //�������䣬�޷���һ��intָ�븳ֵ��һ�������
		std::shared_ptr<int> ptrb = std::make_shared<int>(b);
		ptra2 = ptrb;    //��ֵ,ʹ��ptraӦ������һ��ptrb����������һ

		std::cout << ptra.use_count() << std::endl; //1
		std::cout << ptrb.use_count() << std::endl; //2

		std::cout << *pb << std::endl;   //��ʱpb��ֵΪ10,��Ϊpb�ʼָ��a
		pb = ptrb.get(); //��ȡԭʼָ��
		std::cout << *pb << std::endl;   //��ʱpb��ֵΪ20,��Ϊptrb��ԭʼָ��ָ��b

		int temp;
		std::cin >> temp;

		return 0;
	}
}