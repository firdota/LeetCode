#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		int *nodeOfOneDegree = new int[n];
		bool *ifDelete = new bool[n];
		memset(nodeOfOneDegree,0,n*sizeof(int));
		memset(ifDelete,false,n*sizeof(bool));
		vector<vector<int>> link(n);
		vector<int> result;
		int i,j,numOfOneDegree=0,nodeRemain=n;
		for(i=0;i<edges.size();i++){
			link[edges[i].first].push_back(edges[i].second);
			link[edges[i].second].push_back(edges[i].first);
		}
		
		while(nodeRemain>2){
			numOfOneDegree=0;
			for(i=0;i<n;i++){
				if(link[i].size()==1){
					ifDelete[i]=true;
					nodeRemain--;
					nodeOfOneDegree[numOfOneDegree]=i;
					numOfOneDegree++;
				}
			}
			
			//for(int k=0;k<n;k++){
			//	for(int kk=0;kk<link[k].size();kk++)
			//		cout<<link[k][kk]<<" ";
			//	cout<<endl;
			//}
			for(i=0;i<numOfOneDegree;i++){
				int ii=nodeOfOneDegree[i];
				int temp = link[ii][0];
				for(j=0;j<link.at(temp).size();j++){
					if(link.at(temp).at(j)==ii){
						//cout<<"i="<<ii<<" j="<<j<<endl;
						link.at(temp).erase(link.at(temp).begin()+j);
					
						break;
					}
				}
				link[ii].erase(link.at(ii).begin());
			}
		}
		for(i=0;i<n;i++){
			if(!ifDelete[i])
				result.push_back(i);
		}
		return result;
    }
};
int main(){
	Solution s;
	vector<pair<int,int>> test;
	test.push_back(std::pair<int,int>(3,0));
	test.push_back(std::pair<int,int>(1,3));
	test.push_back(std::pair<int,int>(2,3));
	test.push_back(std::pair<int,int>(4,3));
	test.push_back(std::pair<int,int>(5,4));
	vector<int> result = s.findMinHeightTrees(6,test);
	for(int i=0;i<result.size();i++)
		cout<<result[i]<<endl;
	return 0;
}
