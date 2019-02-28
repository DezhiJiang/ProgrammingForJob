#include<iostream>
#include<memory>

int main()
{
	{
		std::shared_ptr<int> sh_ptr = std::make_shared<int>(10);
		std::cout << sh_ptr.use_count() << std::endl;  //1

		std::weak_ptr<int> wp(sh_ptr);
		std::cout << wp.use_count() << std::endl;      //1, weak_ptrû�й�����Դ�����Ĺ��첻������ָ�����ü���������

		if (!wp.expired())  //expired()�Ĺ��ܵȼ��� use_count()==0,��ʾ���۲����Դ�Ѿ���������
		{
			std::shared_ptr<int> sh_ptr2 = wp.lock(); // lock()�����ӱ��۲��shared_ptr���һ�����õ�shared_ptr���󣬴Ӷ�������Դ
			std::cout << "*sh_ptr2 = " << *sh_ptr << std::endl;  //sh_ptr2ָ��sh_ptrָ���ַ����Դ����������sh_ptr���޸Ķ��޸�
			*sh_ptr = 100;
			std::cout << "*sh_ptr2 = " << *sh_ptr << std::endl;
			std::cout << wp.use_count() << std::endl;  //2
		}

		int temp;
		std::cin >> temp;
	}

	//�ͷ��ڴ�

	return 0;
}