#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
		if(nums.size()<2)
			return;
		int i,j=0,sorted=-1,toSearch=0,temp;
		bool up=true;
		while(true)
		{
			while(toSearch<nums.size())
			{
				//cout<<"what"<<endl;
				while(toSearch<nums.size()&&nums.at(sorted+1)==nums.at(toSearch))toSearch++;
				if(toSearch==nums.size())
					break;
				//cout<<"up: "<<up<<" a1: "<<nums.at(sorted+1)<<" a2: "<<nums.at(toSearch)<<endl;
				//cout<<"bool: "<<(up^(nums.at(sorted+1)<nums.at(toSearch)))<<endl;
				if(up^(nums.at(sorted+1)<nums.at(toSearch)))//choose the smaller
				{
				
					temp=nums.at(sorted+1);
					nums.at(sorted+1)=nums.at(toSearch);
					nums.at(toSearch)=temp;
				}
				up=!up;
				sorted++;
			}
		//for(int i=0;i<nums.size();i++)
		//	cout<<nums.at(i)<<" ";
		//cout<<endl;
			if(sorted==nums.size()-2)
				return;
			for(i=sorted+1;i<nums.size();i+=2)
			{
				while(j<=sorted)
				{
					if(nums.at(i)!=nums.at(j)&&((j==0&&nums.at(i)<nums.at(j+1))||(j%2==0&&j>0&&nums.at(i)<nums.at(j-1)&&nums.at(i)<nums.at(j+1))||(j%2==1&&nums.at(i)>nums.at(j-1)&&nums.at(i)>nums.at(j+1))))
					{
						temp=nums.at(j);
						nums.at(j)=nums.at(i);
						nums.at(i)=temp;
						j++;
						break;
					}
					j++;
				}
			}
			toSearch=sorted+1;
		}
    }
};

int main()
{
	Solution s;
	vector<int> test;
	test.push_back(4);
	test.push_back(5);
	test.push_back(5);
	//test.push_back(1);
	test.push_back(6);
	//test.push_back(4);
	s.wiggleSort(test);
	for(int i=0;i<test.size();i++)
		cout<<test.at(i)<<" ";
	cout<<endl;
	return 0;
}
