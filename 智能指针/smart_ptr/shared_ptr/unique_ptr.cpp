#include<iostream>
#include<memory>

int main()
{
	{
		std::unique_ptr<int> uptr(new int(5));  //�󶨶�̬����
		//std::unique_ptr<int> uptr2 = uptr;  //���ܸ�ֵ
		//std::unique_ptr<int> uptr2(uptr);   //���ܿ���
		std::unique_ptr<int> uptr2 = std::move(uptr);

		uptr2.release();  //�ͷ�����Ȩ
	}
	//����uptr���������ڴ��ͷ�
	return 0;
}