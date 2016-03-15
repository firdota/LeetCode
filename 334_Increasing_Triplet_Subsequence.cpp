#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int a1, a2, a3, i;
		bool f3 = false;
		for (i = 1; i < nums.size(); i++)
		{
			if (nums.at(i) > nums.at(i - 1))
				break;
		}
		if (i < nums.size())
		{
			a1 = nums.at(i - 1);
			a2 = nums.at(i);
		}
		i++;
		for (; i < nums.size(); i++)
		{
			if (nums.at(i)>a2)
				return true;
			else if (nums.at(i)>a1)
				a2 = nums.at(i);
			else
			{
				if (f3&&nums.at(i) > a3)
				{
					a1 = a3;
					a2 = nums.at(i);
					f3 = false;
				}
				else
				{
					f3 = true;
					a3 = nums.at(i);
				}
			}
		}
		return false;
	}
};
int main()
{
	Solution s;
	vector<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(1);
	test.push_back(2);
	test.push_back(2);
	test.push_back(2);
	cout << s.increasingTriplet(test) << endl;
}
