#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
		int n=nums.size();
		int *coins = new int[n*(n+3)/2+1];
		memset(coins,0,(n*(n+3)/2+1)*sizeof(int));
		int i,j,l,left,right,temp;

		for(l=1;l<=n;l++){
			for(i=0;i<=n-l;i++){
				for(j=i;j<i+l;j++){
					if(i==0)
						left=1;
					else
						left=nums[i-1];
					if(i+l==n)
						right=1;
					else
						right=nums[i+l];
					temp=coins[index(n,i,j-1)]+coins[index(n,j+1,i+l-1)]+left*nums[j]*right;
					//cout<<"l="<<l<<" i="<<i<<" j="<<j<<" index1:"<<index(n,i,j-1)<<" index2:"<<index(n,j+1,i+l-1)<<" left="<<left<<" right="<<right<<" temp="<<temp<<endl;
					if(coins[index(n,i,i+l-1)]<temp)
						coins[index(n,i,i+l-1)]=temp;
				}
			}
		}
		//for(i=0;i<n;i++){
		//	for(j=i-1;j<n;j++)
		//		cout<<coins[index(n,i,j)]<<" ";
		//	cout<<endl;
		//}
		//cout<<endl;
		return coins[index(n,0,n-1)];
    }
	int index(int n,int i,int j){
		return (2*n*i+i-i*i+2*j+2)/2;
	}
};
int main(){
	Solution s;
	vector<int> test;
	test.push_back(3);
	test.push_back(1);
	test.push_back(5);
	test.push_back(8);
	cout<<s.maxCoins(test)<<endl;
}
