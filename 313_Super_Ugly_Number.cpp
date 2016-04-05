#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int *uglyNumber = new int[n];
	int *pointer = new int[primes.size()];
	memset(pointer,0,primes.size()*sizeof(int));
	int i=0,j=0,min=0,minIndex=0;
	uglyNumber[0]=1;
	for(i=1;i<n;i++){
		min=INT_MAX;
		for(j=0;j<primes.size();j++){
			if(uglyNumber[pointer[j]]*primes[j]<min){
				minIndex=j;
				min=uglyNumber[pointer[j]]*primes[j];
			}
			else if(uglyNumber[pointer[j]]*primes[j]==min)
				pointer[j]++;
		}
		uglyNumber[i]=min;
		pointer[minIndex]++;
	}
	return uglyNumber[n-1];
    }
};
int main(){
	Solution s;
	vector<int> test;
	test.push_back(2);
	test.push_back(7);
	test.push_back(13);
	test.push_back(19);
	cout<<s.nthSuperUglyNumber(12,test)<<endl;
	return 0;
}
