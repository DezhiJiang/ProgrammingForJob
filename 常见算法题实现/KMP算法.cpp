#include<iostream>
#include<vector>
#include<string>

using namespace std;

void printNext(vector<int> next)
{
	cout << "next: ";
	for (int i = 0; i < next.size(); i++)
	{
		cout << next[i] << " ";
	}
	cout << endl;
}

vector<int> getNext(string ps)
{
	vector<int> next(ps.size());
	next[0] = -1;  //��ʱ��ֻ������������һ��
	int j = 0;
	int k = -1;
	while (j < (ps.size() - 1))
	{
		if (k == -1 || ps[j] == ps[k]) {
			//if (ps[++j] == ps[++k])
			//	next[j] = next[k];
			//else
			//	next[j] = k;
			next[++j] = ++k;
		}
		else
			k = next[k];
	}
	//��ӡ
	printNext(next);

	return next;
}

int KMP(const string &ts, const string &ps)  //ts������ ps: ģʽ��
{
	int i = 0; //������λ��
	int j = 0; //ģʽ����λ��
	vector<int> next = getNext(ps);

	int l_ts = ts.length(), l_ps = ps.length();  //ע�⣺string��size()��length()���ص����޷�������
	                                             //����һ���з�����������һ���޷������������д�С�Ƚ�ʱ�����Ƚ��з���������ת�����޷������������ٽ��бȽ�
	                                             //���һ��һ�������������ķǳ���
	while (i < l_ts && j < l_ps)
	{

#if 1
		if (j == -1 || ts[i] == ps[j])
		{
			i++;
			j++;
		}
		else {
			j = next[j];
		}	

#else
		if (ts[i] == ps[j])
		{
			i++;
			j++;
			cout << "j: " << j << " i :" << i << endl;
		}
		else {
			j = next[j];
			if (j == -1) {
				j = 0;
				i++;
			}
			cout << "j: " << j << " i :" << i << endl;
		}
#endif


	}

	if (j == ps.size())
		return i - j;
	else
		return -1;
}


int main()
{
	string ts, ps;

	while (ts != "/" && ps != "/")
	{
		cout << "����������ts: ";
		cin >> ts;
		cout << "������ģʽ��ps: ";
		cin >> ps;
		cout << "�������Ϊ�� " << KMP(ts, ps) << endl;
	}
}
