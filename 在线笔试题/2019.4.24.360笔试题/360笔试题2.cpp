#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int change(string s)
{
	int res = 0;
	//reverse(s.begin(), s.end());
	int point = 0;  //'.'���ֵĴ�����ֻ�������һ�Σ�����һ�α����쳣���
	int big = 1;    //�����ж�����
	for (int i = 0; i < s.size(); i++)
	{
		if (i == 0 && (s[i] == '+' || s[i] == '-'))  //���жϵ�һ���ַ��Ƿ��ǡ�+�� ��-����
		{
			if (s[i] == '-')
				big = -1;
			continue;
		}
		if ((s[i]<'0' || s[i]>'9')&& s[i]!= '.')
			return 0;
		if (s[i] == '.')
			point++;
		if (point > 1)
			return 0;
		if (point == 0)
		{
			int num = s[i] - '0';
			res = res * 10 + num;
		}
	}

	return res*big;
}

int main()
{
	string str;
	//cin >> str;

	while (cin >> str)
	{
		int res;
		res = change(str);
		cout << res << endl;
	}


	
	return 0;
}



