#include<iostream>
#include<string>
#include<vector>

using namespace std;

//��һ�⣺ ����Ӳ����


//�ڶ��⣺ 01����
//˼·����Ϊ�ַ���������0��1�������������0��1�϶������ڣ���������01��������ַ������Ⱦ���0��1�ĸ�����ľ���ֵ
int findValue(string s, int num)
{
	long count0 = 0, count1 = 0;
	for (int i = 0; i < num; ++i)
	{
		if (s[i] == '1')
			count1++;
		else if (s[i] == '0')
			count0++;
	}

	return abs(count1 - count0);
}

int main()
{
	int num;
	string s;

	while (cin >> num >> s)
	{
		cout << findValue(s, num) << endl;
	}
}


//�����⣺��¸����

//�ⷨһ
#include <iostream>
#include <vector>

using namespace std;

/* tmp:��ǰ���ҵ������±�
    t : ��ǰ����
    p : ��ǰ��¸��Ǯ�� */
void func(const vector<int> &vec_d, const vector<int> &vec_p, vector<int> &ret, const long long &tmp, long long t, long long p)
{
	if (tmp >= vec_d.size())
	{
		ret.push_back(p);
	}
	for (int i = tmp; i < vec_d.size(); i++)
	{
		if (t <= vec_d[i])
		{
			t += vec_d[i];
			p += vec_p[i];
		}
		else
		{
			t += vec_d[i];
			p += vec_p[i];
			func(vec_d, vec_p, ret, i + 1, t, p);
			func(vec_d, vec_p, ret, i + 1, t - vec_d[i], p - vec_p[i]);
		}
	}
	return;
}

int find_min(const vector<int> &ret)
{
	int min = 2147483647;
	int m = INT_MAX;
	for (int i = 0; i < ret.size(); i++)
	{
		if (min > ret[i])
		{
			min = ret[i];
		}
	}
	return min;
}

int main()
{
	int N = 0;
	int tmp = 0;
	long long t = 0;
	cin >> N;
	vector<int> vec_d;
	vector<int> vec_p;
	vector<int> ret;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		vec_d.push_back(tmp);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		vec_p.push_back(tmp);
	}
	func(vec_d, vec_p, ret, 0, t, 0);
	cout << find_min(ret) << endl;
	/*
	for (auto a : ret)
	{
	cout << a << endl;
	}
	*/
	//system("pause");
}

//�ⷨ��
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<long long> battle;
	vector<long long> money;
	long long maxBattle = 0;
	long long maxMoney = 0;
	long long minBattle = 0;
	long long minMoney = 0;
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		battle.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		cin >> a;
		money.push_back(a);
	}
	for (int i = 0; i<n; i++) {
		if (battle[i] <= minBattle) {
			maxBattle = maxBattle + battle[i];
			maxMoney = maxMoney + money[i];
		}
		else if (battle[i] > minBattle && battle[i]<maxBattle) {
			if (minMoney + money[i] <= maxMoney) {
				minMoney = minMoney + money[i];
				minBattle = minBattle + battle[i];
				maxBattle = maxBattle + battle[i];
				maxMoney = maxMoney + money[i];
			}
			else if (minMoney + money[i]>maxMoney) {
				minMoney = maxMoney;
				minBattle = maxBattle;
				maxBattle = maxBattle + battle[i];
				maxMoney = maxMoney + money[i];
			}
		}
		else if (battle[i] >= maxBattle) {
			minMoney = minMoney + money[i];
			minBattle = minBattle + battle[i];
			maxBattle = maxBattle + battle[i];
			maxMoney = maxMoney + money[i];

		}
	}
	cout << minMoney;
}