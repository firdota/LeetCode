#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> results;
		results.push_back(0);
		if (num == 0)
			return results;
		//results.push_back(1);
		int i = 1,j=0,base=1;
		while (2*base - 1 <= num)
		{
			for (j = base; j < 2 * base; j++)
				results.push_back(1 + results.at(j - base));
			i++;
			base = base * 2;
		}
		base = pow(2, i - 1);
		for (j = base; j <= num; j++)
			results.push_back(1 + results.at(j - base));
		return results;
	}
};

int main()
{
	Solution s;
	vector<int> test = s.countBits(5);
	for (int i = 0; i < test.size(); i++)
		cout << test.at(i) << endl;
}
