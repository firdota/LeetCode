#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
bool compare(const string &a, const string &b){
	return a.size() < b.size();
}
class Solution {
public:
	int maxProduct(vector<string>& words) {
		int n = words.size();
		if (n < 2)
			return 0;
		bool *can = new bool[n*(n - 1) / 2];
		memset(can, true, n*(n - 1) / 2 * sizeof(bool));
		int *have = new int[n];
		char k;
		int i, j,top,max=0;
		//sort(words.begin(), words.end(), compare);
		for (k = 'a'; k <= 'z'; k++){
			top = 0;
			for (i = 0; i < n; i++){
				if (words.at(i).find(k) != string::npos)
					have[top++] = i;
			}
			for (i = 0; i < top - 1; i++){
				for (j = i + 1; j < top; j++){
					can[have[i] * (n * 2 - have[i] - 1) / 2 + have[j] - have[i] - 1] = false;
				}
			}
		}
		for (i = n - 2; i >= 0; i--){
			for (j = n - 1; j > i; j--){
				if (can[i*(n*2-i-1)/2+j-i-1]){
					max = max >= words.at(i).size()*words.at(j).size() ? max : words.at(i).size()*words.at(j).size();
				}
			}
		}
		return max;
	}
};

int main(){
	Solution s;
	vector<string> words;
	words.push_back("abcw");
	words.push_back("baz");
	words.push_back("foo");
	words.push_back("bar");
	words.push_back("xtfn");
	words.push_back("abcdef");
	//words.push_back("ac");
	//words.push_back("ce");
	//words.push_back("cefde");
	//words.push_back("dabae");
	cout << s.maxProduct(words) << endl;
	return 0;
}
