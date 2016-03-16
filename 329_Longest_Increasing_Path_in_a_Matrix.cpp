#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
		if(matrix.size()==0)
			return 0;
        vector<vector<int>> longest;
		int i,j,max=1,curMax=1,stage=0;
		for(i=0;i<matrix.size();i++)
		{
			vector<int> tmp(matrix.at(0).size(),1);
			longest.push_back(tmp);
		}
		//cout<<"aht"<<endl;
		while(true)
		{
			for(i=0;i<matrix.size();i++)
			{
				for(j=0;j<matrix.at(0).size();j++)
				{
					if(i>0&&matrix.at(i-1).at(j)>matrix.at(i).at(j))
						longest.at(i).at(j)=longest.at(i).at(j)>=(longest.at(i-1).at(j)+1)?longest.at(i).at(j):longest.at(i-1).at(j)+1;
					if(j>0&&matrix.at(i).at(j-1)>matrix.at(i).at(j))
						longest.at(i).at(j)=longest.at(i).at(j)>=longest.at(i).at(j-1)+1?longest.at(i).at(j):longest.at(i).at(j-1)+1;
					if(i+1<matrix.size()&&matrix.at(i+1).at(j)>matrix.at(i).at(j))
						longest.at(i).at(j)=longest.at(i).at(j)>=(longest.at(i+1).at(j)+1)?longest.at(i).at(j):longest.at(i+1).at(j)+1;
					if(j+1<matrix.at(0).size()&&matrix.at(i).at(j+1)>matrix.at(i).at(j))
						longest.at(i).at(j)=longest.at(i).at(j)>=longest.at(i).at(j+1)+1?longest.at(i).at(j):longest.at(i).at(j+1)+1;
					curMax = curMax>=longest.at(i).at(j)?curMax:longest.at(i).at(j);
				}
			}
			//cout<<curMax<<endl;
			for(i=matrix.size()-1;i>=0;i--)
			{
				for(j=matrix.at(0).size()-1;j>=0;j--)
				{
					if(i>0&&matrix.at(i-1).at(j)>matrix.at(i).at(j))
						longest.at(i).at(j)=longest.at(i).at(j)>=(longest.at(i-1).at(j)+1)?longest.at(i).at(j):longest.at(i-1).at(j)+1;
					if(j>0&&matrix.at(i).at(j-1)>matrix.at(i).at(j))
						longest.at(i).at(j)=longest.at(i).at(j)>=longest.at(i).at(j-1)+1?longest.at(i).at(j):longest.at(i).at(j-1)+1;
					if(i+1<matrix.size()&&matrix.at(i+1).at(j)>matrix.at(i).at(j))
						longest.at(i).at(j)=longest.at(i).at(j)>=(longest.at(i+1).at(j)+1)?longest.at(i).at(j):longest.at(i+1).at(j)+1;
					if(j+1<matrix.at(0).size()&&matrix.at(i).at(j+1)>matrix.at(i).at(j))
						longest.at(i).at(j)=longest.at(i).at(j)>=longest.at(i).at(j+1)+1?longest.at(i).at(j):longest.at(i).at(j+1)+1;
					curMax = curMax>=longest.at(i).at(j)?curMax:longest.at(i).at(j);
				}
			}
			//cout<<curMax<<endl;
			if(curMax>max)
			{
				max=curMax;
				stage=0;
			}
			else
			{
			    stage++;//存在需要连续两次逆序再加一次顺序搜索的情况
			    if(stage>1)
			        break;
			}
		}
		return max;
    }
};
int main()
{
	Solution s;
	vector<vector<int>> test;
	vector<int> a1,a2,a3;
	a1.push_back(3);
	a1.push_back(4);
	a1.push_back(5);
	a2.push_back(3);
	a2.push_back(2);
	a2.push_back(6);
	a3.push_back(2);
	a3.push_back(2);
	a3.push_back(1);
	test.push_back(a1);
	test.push_back(a2);
	test.push_back(a3);
	cout<<s.longestIncreasingPath(test)<<endl;


}
