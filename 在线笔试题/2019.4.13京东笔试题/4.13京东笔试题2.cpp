//4.13����������
//˼·��̰�ģ��Ȱ�ÿ���Ӵ���Ŀ�괮�е�λ��ͳ�Ƴ�����ȡλ��Ŀ�괮��ǰ���λ�ã���ȥƥ����ⲿ������һ���µ�Ŀ�괮��ͬʱ������һ
      //����ѭ����ֱ��Ŀ�괮��Ϊ�ջ��Ӵ���Ŀ�괮����ƥ��λ��
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int findIndex(string s, string p)
{
	int index;
	index = s.find(p);
	if (index != -1)
		return index + p.size() - 1;  //���ظ���������λ��
	else
		return -1;
}

int count(int m, vector<string> strset, string s)
{
	int count = 0;
	vector<int> finalIndex;
	int temp;
	while (1)
	{
		finalIndex.clear();
		for (int i = 0; i < strset.size(); i++)
		{
			temp = findIndex(s, strset[i]);
			if (temp != -1)
				finalIndex.push_back(temp);
		}
		if (finalIndex.size() != 0)
		{
			sort(finalIndex.begin(), finalIndex.end()); //����

			s = s.substr(finalIndex[0] + 1);
			count++;
		}
		else {
			return count;
		}
	}
	return count;
}

int main()
{
	int m;
	vector<string> strset;
	string str;

	cin >> m;
	string temp;
	for (int i = 0; i<m; i++)
	{
		cin >> temp;
		strset.push_back(temp);
	}

	cin >> str;
	int res;
	res = count(m, strset, str);
	cout << res << endl;

	return 0;
}
