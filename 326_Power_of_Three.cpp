#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
        while(n>1)
        {
            if(n%3==0)
                n=n/3;
            else
                return false;
        }
        return true;
    }
	bool isPowerOfThreeMax(int n)
	{
		int max=1162261467;
		if(max%n==0)
			return true;
		else
			return false;
	}
};
int main()
{
	Solution s;
	cout<<s.isPowerOfThreeMax(1162261468)<<endl;
	return 0;
}
