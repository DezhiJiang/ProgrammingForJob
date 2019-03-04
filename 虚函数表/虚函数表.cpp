#include <iostream>

//�ο�������ַ��https://blog.csdn.net/lyztyycode/article/details/81326699

using namespace std;

class Base1 {

public:

	virtual void f() { cout << "Base1::f" << endl; }

	virtual void g() { cout << "Base1::g" << endl; }

	virtual void h() { cout << "Base1::h" << endl; }

};

class Base2 {

public:

	virtual void f() { cout << "Base2::f" << endl; }

	virtual void g() { cout << "Base2::g" << endl; }

	virtual void h() { cout << "Base2::h" << endl; }

};

class Base3 {

public:

	virtual void f() { cout << "Base3::f" << endl; }

	virtual void g() { cout << "Base3::g" << endl; }

	virtual void h() { cout << "Base3::h" << endl; }

};

class Derive : public Base1, public Base2, public Base3 {

public:

	virtual void f() { cout << "Derive::f" << endl; }   //��д�˸�����麯��

	virtual void g1() { cout << "Derive::g1" << endl; } //δ��д������麯��

};

typedef void(*Fun)(void);     //����һ������ָ��

int main()

{

	Fun pFun = NULL;

	Derive d;         //����һ������ʵ������

	int** pVtab = (int**)&d; //ָ���ָ��

	//Base1's vtable

	//pFun = (Fun)*((int*)*(int*)((int*)&d+0)+0);

	pFun = (Fun)pVtab[0][0];  //��һ��������麯����ĵ�һ���麯��

	pFun();      //Derive::f  ��Ϊ��ʱ����麯���ѱ�������д�ˣ����Ե��õ���Derive��f()

	//pFun = (Fun)*((int*)*(int*)((int*)&d+0)+1);

	pFun = (Fun)pVtab[0][1]; //�����е�һ��������麯����ĵڶ����麯��

	pFun();        //Base1::g  ��Ϊ����û����д����麯�������Դ�ӡ�����Base1�� g()

	//pFun = (Fun)*((int*)*(int*)((int*)&d+0)+2);

	pFun = (Fun)pVtab[0][2]; //�����е�һ��������麯����ĵ������麯��

	pFun(); //Base1::h  ��Ϊ����û����д����麯�������Դ�ӡ�����Base1�� h()

	//Derive's vtable

	//pFun = (Fun)*((int*)*(int*)((int*)&d+0)+3);

	pFun = (Fun)pVtab[0][3]; //�����е�һ���麯����ĵ��ĸ��麯��

	pFun();   //Derive::g1 ��Ϊ����ĳ�Ա�������ŵ��˵�һ������ı��С�����ν�ĵ�һ�������ǰ�������˳�����жϵģ�

	//The tail of the vtable

	pFun = (Fun)pVtab[0][4];  //��ӡ�����һ���麯����Ľ����ڵ㣬�����ַ����Ľ�������/0��һ�������־���麯����Ľ�����
	                          //���������־��ֵ�ڲ�ͬ�ı��������ǲ�ͬ�ġ���WinXP+VS2003�£����ֵ��NULL��
	                          //����Ubuntu 7.10 + Linux 2.6.22 + GCC 4.1.3�£����ֵ�����1����ʾ������һ���麯����
	                          //���ֵ��0����ʾ�����һ���麯����

	cout << pFun << endl;    //��ӡ�����00000000

	//Base2's vtable

	//pFun = (Fun)*((int*)*(int*)((int*)&d+1)+0);

	pFun = (Fun)pVtab[1][0];  //�����еڶ��������麯����ĵ�һ���麯��

	pFun();    //Derive::f   ��Ϊ�ѱ�������д����麯������

	//pFun = (Fun)*((int*)*(int*)((int*)&d+1)+1);

	pFun = (Fun)pVtab[1][1];  //�����еڶ��������麯����ĵڶ����麯��

	pFun();  //Base2::g

	pFun = (Fun)pVtab[1][2]; //�����еڶ��������麯����ĵ������麯��

	pFun(); //Base2::h

	//The tail of the vtable

	pFun = (Fun)pVtab[1][3];

	cout << pFun << endl;   ////��ӡ�����00000000

	//Base3's vtable

	//pFun = (Fun)*((int*)*(int*)((int*)&d+1)+0);

	pFun = (Fun)pVtab[2][0];  //�����е����������麯����ĵ�һ���麯��

	pFun();   //Derive::f   ��Ϊ�ѱ�������д����麯������

	//pFun = (Fun)*((int*)*(int*)((int*)&d+1)+1);

	pFun = (Fun)pVtab[2][1];  //�����е����������麯����ĵڶ����麯��

	pFun();   //Base3:g

	pFun = (Fun)pVtab[2][2];  //�����е����������麯����ĵ������麯��

	pFun();   //Base3:h

	//The tail of the vtable

	pFun = (Fun)pVtab[2][3];

	cout << pFun << endl;    ////��ӡ�����00000000

	return 0;

}