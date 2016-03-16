#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
		if(n<1)
			return 0;
		long long i=0,cover=0,num=0;
		while(i<nums.size())
		{
			if(nums.at(i)>cover+1)
			{
				num++;
				cover=2*cover+1;
				if(cover>=n)
					return num;
			}
			else
			{
				cover+=nums.at(i);
				i++;
				if(cover>=n)
					return num;
			}
		}
		while(cover<n)
		{
			num++;
			cover=2*cover+1;
		}
		return num;
    }
};

int main()
{
	Solution s;
	int a[]={1,2,2};
	vector<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(31);
	test.push_back(33);
	//test.push_back();
	cout<<s.minPatches(test,2147483647)<<endl;
	return 0;
}
