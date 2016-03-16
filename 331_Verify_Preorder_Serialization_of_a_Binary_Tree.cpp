#include<iostream>
#include<string>
#include<string>
using namespace std;
class Solution {
public:
    bool isValidSerialization(string preorder) {
		int i,commaIndex=-1,left=0;
		bool dLeft=true;
		preorder.push_back(',');
		preorder.push_back('#');
		for(i=commaIndex+1;i<preorder.size();i++)
		{
			if(preorder.at(i)==',')
			{
				string tmp = preorder.substr(commaIndex+1,i-commaIndex-1);
				//cout<<tmp<<endl;
				if(dLeft)
					left++;
				else
					left--;
				if(left<1)
					return false;
				if(tmp=="#")
					dLeft=false;
				else
					dLeft=true;
				commaIndex=i;
			}
		}
		//cout<<"left "<<left<<endl;
		if(dLeft||left!=1)
			return false;
		return true; 
    }
};
class Solution1 {
public:
    bool isValidSerialization(string preorder) {
		int i,commaIndex=preorder.find_first_of(','),left=0;
		bool dLeft=true;
		if(commaIndex==-1&&preorder.at(0)=='#')
			return true;
		if(commaIndex==-1&&preorder.at(0)!='#')
			return false;
		if(commaIndex!=-1&&preorder.at(0)=='#')
			return false;
		for(i=commaIndex+1;i<preorder.size();i++)
		{
			if(preorder.at(i)==',')
			{
				string tmp = preorder.substr(commaIndex+1,i-commaIndex-1);
				//cout<<tmp<<endl;
				if(dLeft)
					left++;
				else
					left--;
				if(left<0)
					return false;
				if(tmp=="#")
					dLeft=false;
				else
					dLeft=true;
				commaIndex=i;
			}
		}
		string tmp = preorder.substr(commaIndex+1,preorder.size()-1-commaIndex);
		if(tmp!="#")
			return false;
		if(left!=1)
			return false;
		return true; 
    }
};
int main()
{
	Solution s;
	string test="9,3,4,#,#,1,#,#,2,#,6,#,#";
	//int index = test.find_first_of(",");
	cout<<s.isValidSerialization(test)<<endl;
	return 0;
}
