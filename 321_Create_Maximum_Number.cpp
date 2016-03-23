#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	void findMaxN(int *nums,int n,int *result,int len){
		if(n==0)
			return;
		result[0]=nums[0];
		int top=0;
		for(int i=1;i<len;i++)
		{
			int a=nums[i];
			while(top>=0&&result[top]<a&&len-i>=n-top)top--;
			if(top<n-1)
			{
				top++;
				result[top]=a;
			}
		}
	}
	void merge(int* nums1,int size1,int* nums2,int size2,int* result){
		int i1=0,i2=0,j=0,k=size1+size2;
		for(j=0;j<k;j++)
		{
			if((i1<size1&&i2<size2&&nums1[i1]>nums2[i2])|| i2>=size2)
				result[j]=nums1[i1++];
			else if((i1<size1&&i2<size2&&nums1[i1]<nums2[i2])||i1>=size1)
				result[j]=nums2[i2++];
			else if(i1<size1&&i2<size2&&nums1[i1]==nums2[i2])
			{
				if(size1-i1<=size2-i2)
				{
					if(memcmp(&nums1[i1],&nums2[i2],(size1-i1)*sizeof(int))<=0)
						result[j]=nums2[i2++];
					else
						result[j]=nums1[i1++];
				}
				else
				{
					if(memcmp(&nums1[i1],&nums2[i2],(size2-i2)*sizeof(int))<0)
						result[j]=(nums2[i2++]);
					else
						result[j]=nums1[i1++];
				}
			}
		}
	}
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		int i=0,n1=0,n2=0;
		int *result = new int[k*4];
		int *s1=result+k,*s2=s1+k,*temp=s2+k;
		memset(result, 0, k*4*sizeof(int));
		if(nums1.size()==0&&nums2.size()>0)
			findMaxN(&nums2[0],k,result,nums2.size());
		else if(nums2.size()==0&&nums1.size()>0)
			findMaxN(&nums1[0],k,result,nums1.size());
		else
		{
			for(i=0;i<=k;i++)
			{
				n1=nums1.size()>=i?i:nums1.size();
				n2=k-n1;
				if(n2>nums2.size())
					continue;
				findMaxN(&nums1[0],n1,s1,nums1.size());
				findMaxN(&nums2[0],n2,s2,nums2.size());
				merge(s1,n1,s2,n2,temp);
				if(memcmp(&temp[0],&result[0],k*sizeof(int))>0)
					memcpy(&result[0],&temp[0],k*sizeof(int));
			}
		}
		vector<int> r(result,result+k);
		delete []result;
		return r;
	}
};
int main()
{
	vector<int> nums1,nums2;
	nums1.push_back(3);
	nums1.push_back(4);
	nums1.push_back(6);
	nums1.push_back(5);
	nums2.push_back(9);
	nums2.push_back(1);
	nums2.push_back(2);
	nums2.push_back(5);
	nums2.push_back(8);
	nums2.push_back(3);
	//nums.push_back(8);
	//nums.push_back(6);
	vector<int> test;
	test.push_back(1);
	test.push_back(4);
	test.push_back(5);
	Solution s;
	vector<int> result = s.maxNumber(nums1,nums2,5);
	//vector<int> result = s.findMaxN(nums2,6);
	for(int i=0;i<result.size();i++)
		cout<<result.at(i)<<" ";
	cout<<endl;
	return 0;
}
