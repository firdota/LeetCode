#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int i,j,k;
		vector<vector<int>> results = vector<vector<int>>();
		unordered_map<string,int> wordsIndex=unordered_map<string,int>();
		for(i=0;i<words.size();i++)
			wordsIndex.insert(unordered_map<string,int>::value_type(words.at(i),i));
		
		for(i=0;i<words.size();i++)
		{
			
			string s = words.at(i);
			sreverse(s);
			int length=s.length();
			if(length==0)
				continue;

			for(j=0;j<length;j++)
			{
				if(wordsIndex.find(s.substr(0,j))==wordsIndex.end())
					continue;
				
				for(k=0;k<(length-j)/2;k++)
					if(s.at(j+k)!=s.at(length-1-k))
						break;
				if(k<(length-j)/2)
					continue;
				vector<int> temp = vector<int>();
				temp.push_back(wordsIndex.at(s.substr(0,j)));
				temp.push_back(i);
				results.push_back(temp);
			}
			for(j=1;j<=length;j++)
			{
				if(wordsIndex.find(s.substr(j,length-j))==wordsIndex.end())
					continue;
				for(k=0;k<j/2;k++)
					if(s.at(k)!=s.at(j-1-k))
						break;
				if(k<j/2)
					continue;
				vector<int> temp = vector<int>();
				temp.push_back(i);
				temp.push_back(wordsIndex.at(s.substr(j,length-j)));
				results.push_back(temp);
			}
			if(wordsIndex.find(s)!=wordsIndex.end()&&wordsIndex.at(s)!=i)
			{
				vector<int> temp = vector<int>();
				temp.push_back(i);
				temp.push_back(wordsIndex.at(s));
				results.push_back(temp);
			}
		}
		return results;
    }
	void sreverse(string &s)
	{
		int length=s.length();
		for(int i=0;i<length/2;i++)
		{
			char temp=s.at(i);
			s.at(i)=s.at(length-1-i);
			s.at(length-1-i)=temp;
		}
	}
};

int main()
{
	Solution s = Solution();
	vector<string> test = vector<string>();
	test.push_back("aaaaabaababbaabababbbababbabbabbabaaabababbbbbbbaaaaabbbbabbababababbaaababbbbabbbbbaaaabaababbbaba");
	test.push_back("babbbaaaaabaababaabbbaaaaaabaa");
	test.push_back("baaaaabbbaabaaaaaaabaaabbbaabbabbaaabbbbababaaaaabbabbaabaaabbbbaabbbaababbbbabaaaabababbbaaabbbba");
	test.push_back("aabbaabaabaabbba");
	test.push_back("babbaaaabbababababbababaabbbbabbaabababb");
	test.push_back("bbbbabbaabbaaaabaaabbbbbbaaaaaaaaa");
	test.push_back("bbbbbaababababbaaaabb");
	test.push_back("aabbabaabbbbbbbbbaaab");
	test.push_back("abbabbaabaabaaa");
	test.push_back("bbbbbaababababbaaaabb");
	test.push_back("bbbbabbbbaaaaaaabbbabaababbbbaaaaabaaabaaabababbaaababaaababbaabaaaaabaabbababaabaaaaaaaabb");
	vector<string> test1 = vector<string>();
	test1.push_back("a");
	test1.push_back("abc");
	test1.push_back("aba");
	test1.push_back("");
	//test.push_back("");
	vector<vector<int>> results = s.palindromePairs(test1);
	for(int i=0;i<results.size();i++)
	{
		for(int j=0;j<results.at(i).size();j++)
			cout<<results.at(i).at(j)<<" ";
		cout<<endl;
	}
}
