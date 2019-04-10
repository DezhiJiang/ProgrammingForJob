#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
private:
	int expandAroundCenter(string s, int left, int right)
	{
		int L = left, R = right;
		int len = s.size();
		
		while (L >= 0 && R < len && s[L] == s[R])
		{
			L--;
			R++;
		}

		return R - L - 1;  //���ش˴�������չ���ҵ���������Ӵ�
	}

public:
	string longestPalindrome(string s)
	{
		if (s.size() < 1 || s == "")
			return "";

		int start = 0, end = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int len1 = expandAroundCenter(s, i, i);   //�����Ӵ���Ψһ���ĵ����
			int len2 = expandAroundCenter(s, i, i + 1); //�����Ӵ����ҶԳ����
			int len = max(len1, len2);

			if (len > (end - start))
			{
				start = i - (len - 1) / 2;  //�����Ӵ�����ʼλ��
				end = i + len / 2;          //�����Ӵ��Ľ���λ��,len/2����ȡ��
			}
		}
		int res_len = end - start + 1; //�����Ӵ��ĳ���
		return s.substr(start, res_len); //substr�ĵ�һ����������ʼλ�ã��ڶ����������Ӵ�����
	}
};

int main()
{
	Solution s;
	string str = "babad";
	string substr = s.longestPalindrome(str);

	cout << substr << endl;
}