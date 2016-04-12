#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int size = prices.size(),i;
		if(size<2)
			return 0;
		int *sold = new int[size],*cool=new int[size];
		cool[0]=0;
		cool[1]=0;
		sold[1]=prices[1]-prices[0];
		for(i=2;i<size;i++){
			cool[i]=cool[i-1]>sold[i-1]?cool[i-1]:sold[i-1];
			sold[i]=prices[i]-prices[i-1]+(cool[i-2]>sold[i-1]?cool[i-2]:sold[i-1]);
		}
		return cool[size-1]>sold[size-1]?cool[size-1]:sold[size-1];
    }
};
int main(){
	Solution s;
	vector<int> test;
	test.push_back(6);
	test.push_back(1);
	test.push_back(6);
	test.push_back(4);
	test.push_back(3);
	test.push_back(0);
	test.push_back(2);
	cout<<s.maxProfit(test)<<endl;
	return 0;
}
