#include<iostream>
#include<stack>
#include<vector>

using namespace std;

//���ڵ�Ľṹ
typedef struct node{
	char  data;
	struct node *lchild;
	struct node *rchild;
	node(char c) :data(c), lchild(nullptr), rchild(nullptr) {};  //���캯��
} BinTreeNode, *BinTree;  //*BinTree����˼�Ǹ� struct node*���˸���������BinTree����BinTreeΪָ��ڵ��ָ�롣

//���������������һ�ö�����
void createBinTree(BinTree &T) //&����˼�Ǵ������ڵ�ָ������ã������ڵȼ��� BinTreeNode* &T,Ŀ�����ô��ݽ�����ָ�뷢���ı�
{
	//ע������������ʱҪ��֤�������е�Ҷ�ӽڵ㶼Ϊ '#',���ܴ�����ɣ������Ȼ�������ͼ������ڵ�ֵ
	//����ab##c##
	
	char c;
	cin >> c;
	if ('#' == c)  //������#��ʱ�������ĸ��ڵ�Ϊnullptr,�Ӷ������÷�֧�ĵݹ�
	{

		T = nullptr;
		return;
	}

	T = new BinTreeNode(c);
	createBinTree(T->lchild);
	createBinTree(T->rchild);

}

/*******  �����������ֵݹ���� *******/

//����ݹ����
//��ӡ˳�� ���ڵ�-���ӽڵ�-���ӽڵ�
void preTraverse(BinTree T) 
{
	if (T != nullptr)
	{
		cout << T->data << " ";
		preTraverse(T->lchild);
		preTraverse(T->rchild);
	}
}

//����ݹ����
//��ӡ˳�� ���ӽڵ�-���ڵ�-���ӽڵ�
void midTraverse(BinTree T)
{
	if (T != nullptr)
	{
		midTraverse(T->lchild);
		cout << T->data << " ";
		midTraverse(T->rchild);
	}
}

//����ݹ����
//��ӡ˳�����ӽڵ�-���ӽڵ�-���ڵ�
void postTraverse(BinTree T)
{
	if (T != nullptr)
	{
		postTraverse(T->lchild);
		postTraverse(T->rchild);
		cout << T->data << " ";
	}
}

/*********   �����������ַǵݹ������ʽ  ************/
//�������ķǵݹ������ʽ����Ҫ����ջȥģ��ʵ��

//�ǵݹ��������
//��Ҫһ�������ڵ�ָ��P
//������̣�1.�����ڵ�ǿգ��򽫸��ڵ���ջ
          //2.�ж�ջ�Ƿ�Ϊ�գ���ջ�ǿգ���Pָ��ָ��ջ���ڵ㣬��ӡ�ڵ����ݲ�ִ�г�ջ������
                                        //ͬʱ�Ⱥ��жϣ���P�ڵ�����ӽڵ�ǿգ���ýڵ���ջ
		                                              //��P�ڵ�����ӽڵ�ǿգ���ýڵ���ջ 
                             //��ջΪ�գ���������
          //�ظ���2������
void preTraverse2(BinTree T)
{
	if (T == nullptr)
		return;

	stack<BinTree> s;
	s.push(T);
	BinTree p = nullptr;
	while (!s.empty())
	{
		p = s.top();
		cout << p->data << " ";
		s.pop();
		if (p->rchild != nullptr)
			s.push(p->rchild);
		if (p->lchild != nullptr)
			s.push(p->lchild);
	}
}

//�ǵݹ��������
//������̣�������һ�ڵ㣬
          //1.�������Ӳ�Ϊ�գ���P��ջ����P��������Ϊ��ǰ��P,Ȼ��Ե�ǰ�ڵ�P�ٽ�����ͬ�Ĵ���
          //2.��������Ϊ�գ���ȡջ��Ԫ�ز����г�ջ���������ʸ�ջ���ڵ㣬Ȼ�󽫵�ǰ��P��Ϊջ���ڵ���Һ���
          //3.ֱ��PΪNULL����ջΪ�����������
void midTraverse2(BinTree T)
{
	if (T == nullptr)
		return;

	stack<BinTree> s;
	BinTree p = T;
	while (p != nullptr || !s.empty())
	{
		if (p != nullptr)
		{
			s.push(p);
			p = p->lchild;
		}
		else
		{
			p = s.top();
			s.pop();
			cout << p->data << " ";
			p = p->rchild;
		}
	}
}

//�ǵݹ������������һ
//˼·����Ҫ����һ���������͸����ڵ�ָ��P����Ϊ���������˳�������Ҹ������Ը��ڵ�һ����������棬�����ʼ�����ڵ����ջ��
      //Ȼ��ʼһ��ѭ����ѭ��������Ϊջ�ǿա�ÿ��ȡ��ջ��Ԫ�أ�����Pָ��ָ��ջ��Ԫ�أ�ͬʱ����Ԫ�ز��뵽�������Ŀ�ʼλ�ã�
      //Ȼ�����Ρ��жϵ�����ջ��Ԫ���Ƿ������ӽڵ�����ӽڵ㣨ע��˳�����Ҫ����Ϊջ�Ǻ���ȳ�������Ҫ���ж������ж��ң�
      //�����ӽڵ�����ӽڵ�ǿգ��򽫸ýڵ�����ջ�У�Ȼ�����¿�ʼ��һ��ѭ��
      //���˳���ӡ���������е�Ԫ�ؼ��ɣ���Ϊÿ�ζ��ǲ������������ǰ�棬����˳��պ��Ǻ������˳��
void postTraverse2_1(BinTree T)
{
	if (T == nullptr)
		return;

	stack<BinTree> s;
	vector<char> rs;
	s.push(T);
	BinTree p = nullptr;
	while (!s.empty())
	{
		p = s.top();
		s.pop();
		rs.insert(rs.begin(), p->data);  //����ǰ�ڵ�����ݲ��뵽����������ǰ��
		if (p->lchild)          //��Ϊջ�ĺ���ȳ�ԭ������Ӧ���Ȳ���ڵ����ҽڵ�
			s.push(p->lchild);  //�����Ļ��ͻ�ci
		if (p->rchild)
			s.push(p->rchild);
	}
	for (int i = 0; i < rs.size(); i++)
		cout << rs[i] << " ";
}
//�ǵݹ��������������
//˼·��Ҫ��֤����������Ӻ��Һ��ӷ���֮����ܷ��ʣ���˶�����һ���P���Ƚ�����ջ��
      //���P���������Ӻ��Һ��ӣ������ֱ�ӷ�������
      //����P�������ӻ����Һ��ӣ����������Ӻ��Һ��Ӷ��ѱ����ʹ��ˣ���ͬ������ֱ�ӷ��ʸý�㡣
      //�������������������P���Һ��Ӻ�����������ջ�������ͱ�֤��ÿ��ȡջ��Ԫ�ص�ʱ��
      //�������Һ���ǰ�汻���ʣ����Ӻ��Һ��Ӷ��ڸ����ǰ�汻���ʡ�
void postTraverse2_2(BinTree T)
{
	stack<BinTree> s;
	BinTree cur = nullptr;   //��ǰ�ڵ�
 	BinTree pre = nullptr;   //ǰһ�η��ʵĽڵ�
	s.push(T);
	while (!s.empty())
	{
		cur = s.top();
		if ((cur->lchild == nullptr &&cur->rchild == nullptr) ||
			(pre != nullptr && (pre == cur->lchild || pre == cur->rchild))) //��ΪֻҪǰһ���ڵ�������ڵ���ӽڵ㣬˵������ڵ���һ�����ڵ��ˣ��ӽڵ��Ѿ���ǰ��������ʱ����ڵ�Ҳ�õ�����
		{                                                                   //�ж������ӽڵ�������ӽڵ���Ҫ�ǿ��ǿ���ֻ��һ�����ӽڵ��������ѣ���ֻҪǰһ���Ǹýڵ���ӽڵ㣬�˽ڵ���ܵ���
			cout << cur->data << " ";   //�����ǰ���û�к��ӽ����ߺ��ӽڵ㶼�ѱ����ʹ� 
			s.pop();
			pre = cur;
		}
		else
		{
			if (cur->rchild != nullptr)
				s.push(cur->rchild);
			if (cur->lchild != nullptr)
				s.push(cur->lchild);
		}
	}
}


int main()
{
	//����������ab#c##de##f## (Ҫ��֤����#����һ����ȫ������)
	          //������������abcdef
	          //������������bcaedf
	          //�������������cbefda
	BinTree T;
	cout << "��ʼ���������������������ڵ㣺";
	createBinTree(T);
	cout << "������������ɣ�" << endl;

	cout << "�ݹ����������������" << endl;
	preTraverse(T);
	cout << endl;
	cout << "�ǵݹ����������������" << endl;
	preTraverse2(T);
	cout << endl;
	cout << "�ݹ����������������" << endl;
	midTraverse(T);
	cout << endl;
	cout << "�ǵݹ����������������" << endl;
	midTraverse2(T);
	cout << endl;
	cout << "�ݹ���������������" << endl;
	postTraverse(T);
	cout << endl;
	cout << "�ǵݹ���򷽷�һ������������" << endl;
	postTraverse2_1(T);
	cout << endl;
	cout << "�ǵݹ���򷽷���������������" << endl;
	postTraverse2_2(T);
	cout << endl;

	////��ֹ��������
	//int temp;
	//cin >> temp;
	
	//VS2017����������к��������⣺
	//�޸���Ŀ���ã��Ҽ������Ŀ�����Ҽ��˵���ѡ�����ԣ�
	//Ȼ���ڵ����ĶԻ�������б���ѡ�� ����������--->������--->ϵͳ����
	//Ȼ�����Ҳ���б��У��ڵ�һ�� ����ϵͳ����ֵ�� ѡ�� ������̨(/ SUBSUSTEM:CONSOLE)��

	return 0;
}


