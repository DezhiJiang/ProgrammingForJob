#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<iterator>

using namespace std;

class Solution {
public:
	//�����������õݹ飬��DFS)�˷����϶�̬�滮Ҫ�úܶ�
	//�ο����ӣ�https://blog.csdn.net/fys465253658/article/details/81215869
	//����˼�룺������˵����������⣬���� nums = [1, 5, 4, 3, 7];
	//��һ�����������������nums = [1, 3, 4, 5, 7], �����͵�һ�� half = 10; ����������Ԫ��Ҫô����һ���Ӽ��У�Ҫô������һ���Ӽ��С�
	//�ڶ���������1�����һ���Ӽ��У��൱����[3, 4, 5, 7]��ȥ��һ���Ӽ���Ϊ9���ټ���1���Ԫ�أ�����1������һ���Ӽ��У����Ծ��൱����[3, 4, 5, 7] ����һ��������Ϊ10 ���Ӽ���������ǿ��Ի�õݹ鷽��ʽ��
	//recur(nums, 0, 10) = recur(nums, 1, 9) || recur(nums, 1, 10);
	bool canPartition(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int sum = accumulate(nums.begin(), nums.end(), 0); //���
		if (sum % 2)  //�жϺ��Ƿ���ż������Ϊ������϶����ܻ��ֵȺ��Ӽ�
			return false;
		int half = sum / 2; //��ȡ�Ӽ��ĺͣ��ܺ͵�һ�룩
		auto iter = max_element(nums.begin(), nums.end()); //����ֵ����Ԫ��
		if (*iter > half)  //�����Ԫ��ֵ�ͳ����ܺ͵�һ�룬��϶����ܻ��ֵȺ��Ӽ�
			return false;
		if (*iter == half) //�����Ԫ��ֵ�����ܺ͵�һ�룬��϶��ܻ��ֵȺ��Ӽ���������һ���Ӽ�ֻ��һ��Ԫ��
			return true;
		vector<int> res(half + 1, 0);
		res[0] = 1;  //����0�����ܴճɺ�Ϊ0���Ӽ�
		for (size_t i = 0; i < nums.size(); ++i)
		{
			for (int j = half; j >= nums[i]; j--)
			{
				if (res[j - nums[i]])
				{
					res[j] = 1;
					if (j == half)
						return true;
				}
			}
		}
		return res[half];
	}

	//DFS���˷�����洢�����һ���Ӽ����±�����
	bool dfs(vector<int> &nums, vector<int> &index, int target, int i)
	{
		if (target == 0)
			return true;
		else if (target > 0)
		{
			for (int j = i; j < nums.size(); j++)
			{
				index.push_back(j);
				if (!dfs(nums, index, target - nums[j], j + 1))
				{
					index.pop_back();
				}
					
				else
					return true;
			}
		}

		return false;
	}
};

int main()
{
	Solution s;
	int size;
	cin >> size;
	vector<int> nums;
	int temp;
	for (int i = 0; i < size; i++)
	{
		cin >> temp;
		nums.push_back(temp);
	}

	int sum = accumulate(nums.begin(), nums.end(), 0); //���
	sort(nums.begin(), nums.end());   //����
	bool canOrnot = false;
	vector<int> index;    //���һ���Ӽ�������
	//canOrnot = s.canPartition(nums);
	canOrnot = s.dfs(nums, index, sum / 2, 0);
	cout <<"can Or not is  " <<canOrnot << endl;
	cout << endl;

	if (canOrnot) // ������Ի��֣���ӡ�����Ӽ�
	{
		vector<int> list1;
		vector<int> list2;
		vector<int>::iterator temp;

		for (int i = 0; i < nums.size(); i++)
		{
			temp = find(index.begin(), index.end(), i);
			if (temp != index.end())
				list1.push_back(nums[i]);
			else
				list2.push_back(nums[i]);
		}

		for (int i = 0; i < list1.size(); i++)
			cout << list1[i] << " ";
		cout << endl;

		for (int i = 0; i < list2.size(); i++)
			cout << list2[i] << " ";
		cout << endl;
	}
}
