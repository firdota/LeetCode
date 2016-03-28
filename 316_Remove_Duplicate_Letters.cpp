#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
    int *count = new int[26];
	memset(count,0,26*sizeof(int));
	bool *added = new bool[26];
	memset(added,false,26*sizeof(bool));
	for(int i=0;i<s.size();i++)
		count[s.at(i)-'a']++;
	vector<char> letters;
	for(int i=0;i<s.size();i++){
		char cur=s.at(i);
		if(letters.empty()){
			letters.push_back(cur);
			added[cur-'a']=true;
		}
		else{
			if(!added[cur-'a']){
				while(!letters.empty()&&letters.back()>cur&&count[letters.back()-'a']>0){
					added[letters.back()-'a']=false;
					letters.pop_back();
				}
				letters.push_back(cur);
				added[cur-'a']=true;
			}
		}
		count[cur-'a']--;
	}
	string result=string(letters.begin(),letters.end());
	return result;
	}
};
int main(){
	Solution s;
	string test="cbacdcbc";
	cout<<s.removeDuplicateLetters(test)<<endl;
	return 0;
}
