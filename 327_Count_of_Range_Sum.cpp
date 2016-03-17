#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
		if(nums.size()==0)
			return 0;
		vector<long long> sum;
		int i;
		sum.push_back(nums.at(0));
		for(i=1;i<nums.size();i++)
			sum.push_back(sum.back()+nums.at(i));
		//for(i=0;i<nums.size();i++)
		//	cout<<sum.at(i)<<endl;
		int result=mergeSort(sum,0,sum.size()-1,lower,upper);
		//for(i=0;i<nums.size();i++)
		//	cout<<sum.at(i)<<endl;
		return result;
    }
	int mergeSort(vector<long long> &sum,int left,int right,int lower,int upper)
	{
		if(left>right)
			return 0;
		if(left==right&&sum.at(left)>=lower&&sum.at(left)<=upper)
			return 1;
		if(left==right&&(sum.at(left)<lower||sum.at(left)>upper))
			return 0;
		int i,j,k,mid=(left+right)/2;
		int ranges=mergeSort(sum,left,mid,lower,upper)+mergeSort(sum,mid+1,right,lower,upper);
		for(i=left,j=mid+1;i<=mid;i++)
		{
			while(j<=right&&sum.at(j)-sum.at(i)<lower)j++;
			k=j;
			while(k<=right&&sum.at(k)-sum.at(i)<=upper)k++;
			ranges += k-j;
		}
		vector<long long> cache;
		for(i=0,j=left,k=mid+1;i<=right-left;i++)
		{
			if((j<=mid&&k<=right&&sum.at(j)<=sum.at(k))||k>right)
				cache.push_back(sum.at(j++));
			else
				cache.push_back(sum.at(k++));
			//cout<<"k= "<<k<<" mid= "<<mid<<" right= "<<right<<endl;
		}
		for(i=0;i<=right-left;i++)
			sum.at(left+i)=cache.at(i);
		//for(i=0;i<=right-left;i++)
		//	cout<<cache.at(i)<<" ";
		//cout<<endl;
		return ranges;
	}
};

int main()
{
	Solution s;
	vector<int> test;

	test.push_back(2147483647);
	test.push_back(-2147483648);
	test.push_back(-1);
	test.push_back(0);
	cout<<s.countRangeSum(test,-1,0)<<endl;
}
