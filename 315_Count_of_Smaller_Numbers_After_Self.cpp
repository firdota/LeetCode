#include<iostream>
#include<vector>
#include<random>
#include<ctime>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
		int size=nums.size();
		vector<int> result(size,0);
		if(nums.empty()){
			return result;
		}
		int i=0,j=0;
		cout<<size<<endl;
		int* index = new int[size];
		for(i=0;i<nums.size();i++)
			index[i]=i;
		devideQonquer(&nums[0],index,&result[0],0,nums.size()-1);
		return result;
    }
	void devideQonquer(int *nums,int *index,int *result,int begin,int end){
		if(end-begin<1)
			return;
		int i=0,i1,i2,middle = (begin+end)/2;

		devideQonquer(nums,index,result,begin,middle);
		devideQonquer(nums,index,result,middle+1,end);
		
		for(i=begin;i<=middle;i++){
			result[index[i]]+=binarySmaller(nums,middle+1,end,nums[i]);

		}
		int *tempNum=new int[end-begin+1],*tempIndex=new int[end-begin+1];
		for(i=0,i1=begin,i2=middle+1;i<end-begin+1;i++){
			if(i1<=middle&&i2<=end){
				if(nums[i1]>=nums[i2]){//取大的i1
					tempNum[i]=nums[i1];
					tempIndex[i]=index[i1++];
				}
				else{
					tempNum[i]=nums[i2];
					tempIndex[i]=index[i2++];
				}
			}
			else if(i2>end){//取i1
				memcpy(tempNum+i,&nums[i1],(middle-i1+1)*sizeof(int));
				memcpy(tempIndex+i,index+i1,(middle-i1+1)*sizeof(int));
				break;
			}
			else{
				memcpy(tempNum+i,&nums[i2],(end-i2+1)*sizeof(int));
				memcpy(tempIndex+i,index+i2,(end-i2+1)*sizeof(int));
				break;
			}
		}
		memcpy(&nums[begin],tempNum,(end-begin+1)*sizeof(int));
		memcpy(index+begin,tempIndex,(end-begin+1)*sizeof(int));
	}
	int binarySmaller(int* nums,int begin,int end,int target){
		if(end<begin)
			return 0;
		int left=begin,right=end,middle;
		while(left<=right){
			middle=(left+right)/2;
			if(nums[middle]>=target)
				left=middle+1;
			else
				right=middle-1;
		}
		return end-right;
	}
	void quitSort(vector<int>& nums,int *index,int begin,int end){//降序
		if(begin>=end)
			return;
		int random=rand()%(end-begin+1)+begin,temp,tempIndex,left=begin,right=end;
		temp=nums.at(begin);tempIndex=index[begin];
		nums.at(begin)=nums.at(random);index[begin]=index[random];
		nums.at(random)=temp;index[random]=tempIndex;
		int key=nums.at(begin);
		while(left<right){
			while(right>left&&nums.at(right)<key)right--;
			while(left<right&&nums.at(left)>=key)left++;
			if(left==right)
				break;
			else{
				temp=nums.at(left);tempIndex=index[left];
				nums.at(left)=nums.at(right);index[left]=index[right];
				nums.at(right)=temp;index[right]=tempIndex;
				right--;
			}
		}
		temp=nums.at(left);tempIndex=index[left];
		nums.at(left)=nums.at(begin);index[left]=index[begin];
		nums.at(begin)=temp;index[begin]=tempIndex;
		quitSort(nums,index,begin,left-1);
		quitSort(nums,index,left+1,end);
	}
};

int main(){
	srand((unsigned int)time(0));
	vector<int> test;
	test.push_back(5);
	test.push_back(2);
	test.push_back(6);
	test.push_back(1);
	Solution s;
	vector<int> result = s.countSmaller(test);
	for(int i=0;i<result.size();i++)
		cout<<result.at(i)<<" ";
	cout<<endl;
	return 0;
}
