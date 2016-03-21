#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		if(coins.size()==0)
			return -1;
		vector<int>  nums(coins.size(),0);
		sort(coins.begin(),coins.end());
		int remain=amount,curCoin=coins.size()-1,sum=0,min=-1;
		bool needBack=false;
		//cout<<remain<<endl;
		while(true)
		{
			nums.at(curCoin)=remain/coins.at(curCoin);
			sum+=remain/coins.at(curCoin);
			//cout<<"curCoin: "<<curCoin<<"      nums.at(curCoin): "<<nums.at(curCoin)<<endl;
			remain=remain%coins.at(curCoin);
			if(remain==0)
			{
				if(min==-1)
					min=sum;
				else
					min=min>sum?sum:min;
				//cout<<"min= "<<min<<endl;
				needBack=true;
			}
			else if((curCoin==0&&remain!=0)||(min>=0&&sum>=min))
			{
				//cout<<"remain= "<<remain<<endl;
				needBack=true;
			}
			else
				needBack=false;
			if(needBack)
			{
				if(curCoin==0||(min>=0&&sum>=min))
				{
					remain+=nums.at(curCoin)*coins.at(curCoin);
					sum-=nums.at(curCoin);
					nums.at(curCoin)=0;
					curCoin++;
				}
				//cout<<"what tf\n"<<"sum = "<<sum<<" remain= "<<remain<<" curCoin= "<<curCoin<<endl;
				//for(int i=0;i<nums.size();i++)
				//	cout<<nums.at(i)<<" ";
				//cout<<endl;
				while(curCoin<nums.size()&&nums.at(curCoin)==0)curCoin++;
				//cout<<curCoin<<" "<<nums.at(curCoin)<<" "<<remain<<endl;
				if(curCoin>=nums.size())
					return min;
				nums.at(curCoin)--;
				sum--;
				remain+=coins.at(curCoin);
			}
			curCoin--;
		}
		return min;
    }
};
int main()
{
	Solution s;
	vector<int> coins;
	coins.push_back(186);
	coins.push_back(419);
	coins.push_back(83);
	coins.push_back(408);
	cout<<s.coinChange(coins,6249)<<endl;
	return 0;
}
