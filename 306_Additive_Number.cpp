#include<iostream>
#include<string>
#include <sstream>
using namespace std;
class Solution {
public:
    bool isAdditiveNumber(string num) {
		unsigned int size = num.size(),i,j,a,b,pos,sum;
		
		for(i=1;i<=size/2;i++){
			for(j=1;j<=size*2/3-i;j++){
				string tempa = num.substr(0,i),tempb=num.substr(i,j);
				if((i>1&&tempa[0]=='0')||(j>1&&tempb[0]=='0'))
					continue;
				a=atoi(num.substr(0,i).c_str());
				b=atoi(num.substr(i,j).c_str());
				//cout<<a<<" "<<b<<endl;
				pos=i+j;
				while(true){
					sum=a+b;
					stringstream ss;
					ss<<sum;
					string temp=ss.str();
					//cout<<"temp: "<<temp<<endl;
					if(temp.size()+pos<=size&&temp==num.substr(pos,temp.size())){
						a=b;
						b=sum;
						pos+=temp.size();
						if(pos==size)
							return true;
					}
					else
						break;
				}
			}
		}
		return false;
    }
};
int main(){
	Solution s;
	string test = "101";
	cout<<s.isAdditiveNumber(test)<<endl;
	return 0;
}
