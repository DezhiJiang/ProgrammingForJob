#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

//˫�˶���
//�ײ�ʵ�֣�ѭ������
//��vector������ deque�����ڳ���ʱ���ڶ�ͷ�˽���Ԫ�صĲ�����Ƴ�������
                  //dequeû�������ĸ�����Ƕ�̬���Էֶ������ռ���϶��ɣ���ʱ��������һ���µĿռ䲢��������
//��deque�������������Ϊ���Ч�ʿɽ�deque����������һ����vector���ϣ���vector������ٸ��ƻ�deque
//deque��vector���ӵĶ࣬Ӧ������vector


int main()
{
	//�ӿ�
	deque<int> que;//������һ�����͵�˫�˶���;
	//que.assign(beg, end) ��[beg; end)�����е����ݸ�ֵ��que��
	//que.assign(n, elem) ��n��elem�Ŀ�����ֵ��que��
	//que.at(idx) ��������idx��ָ�����ݣ����idxԽ�磬�׳�out_of_range��
	//que.back() ��������que�����һ��Ԫ�ص����á����queΪ�գ���ò���δ���塣
	//que.begin() ���ص������еĵ�һ�����ݵ�ַ��
	//que.clear() �Ƴ��������������ݡ�
	//que.empty() �ж������Ƿ�Ϊ�ա�
	//que.end() ����һ������������ָ������que�����һ��Ԫ�ص���һλ�á�
	//que.erase(pos) ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
	//que.erase(beg, end) ɾ��[beg, end)��������ݣ�������һ�����ݵ�λ�á�
	//que.front() ��������que�ĵ�һ��Ԫ�ص����á����queΪ�գ���ò���Ϊ�ա�
	//que.insert(pos, elem) ��posλ�ò���һ��elem����������������λ��
	//que.insert(pos, n, elem) ��pos����������λ�ò���>n��elem���ݡ��޷���ֵ

	//que.insert(pos, beg, end) ��posλ�ò�����[beg, end)��������ݡ��޷���ֵ
	//que.max_size() ��������que�����ɵ����Ԫ�ظ�����
	//que.pop_back() ɾ�����һ�����ݡ�
	//que.pop_front() ɾ��ͷ�����ݡ�
	//que.push_back(elem) ��β������һ�����ݡ�
	//que.push_front(elem) ��ͷ������һ�����ݡ�
	//que.rbegin() ����һ���������������ָ������que�����һ��Ԫ�ء�
	//que.rend() ����һ���������������ָ������que�ĵ�һ��Ԫ�ص�ǰһ��λ�á�
	//que.resize(num) ����ָ�����еĳ��ȡ�
	//que.size() ����������ʵ�����ݵĸ�����
	//que.swap(que2) ��������que��que2�е�����Ԫ�ء�
	//swap(que1, que2) ��������que1��que2�е�����Ԫ�ء�

	deque <int> que;
	que.push_back(1);
	que.push_back(2);
	que.push_back(3);
	cout << "����������" << endl;
	cout << "���б�����" << endl;
	deque<int>::iterator ator;
	for (ator = que.begin(); ator != que.end(); ator++)
		cout << *ator << endl;
	int a;
	cout << "���ײ���Ԫ�أ�";
	cin >> a;
	que.push_front(a);
	cout << "���б�����" << endl;
	for (ator = que.begin(); ator != que.end(); ator++)
		cout << *ator << endl;
	cout << "��β����Ԫ�أ�";
	cin >> a;
	que.push_back(a);
	cout << "���б�����" << endl;
	for (ator = que.begin(); ator != que.end(); ator++)
		cout << *ator << endl;
	cout << "�м����Ԫ�أ�";
	cin >> a;
	que.insert(que.begin() + 1/*������λ�ã�����Ҫ�����*/, 1, a);//��һ��λ��Ϊ������λ�ã��ó�������Ϊ����λ��֮�󡢵�һ��Ԫ��֮ǰ���롣Ԫ�ر�Ŵӵ�0����ʼ�� 
	cout << "���б�����" << endl;
	for (ator = que.begin(); ator != que.end(); ator++)
		cout << *ator << endl;
	cout << "ɾ������Ԫ�أ�" << endl;
	que.pop_front();
	cout << "���б�����" << endl;
	for (ator = que.begin(); ator != que.end(); ator++)
		cout << *ator << endl;
	cout << "ɾ����βԪ�أ�" << endl;
	que.pop_back();
	cout << "���б�����" << endl;
	for (ator = que.begin(); ator != que.end(); ator++)
		cout << *ator << endl;
	cout << "����Ԫ�ظ�����" << que.size() << endl;
	cout << "������0:" << endl;
	que.clear();
	cout << "����Ԫ�ظ�����" << que.size() << endl;
	return 0;
}