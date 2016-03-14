#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
   int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct robbedOrNot
{
	TreeNode* node;
	int robbed;
	int notRobbed;
	robbedOrNot(TreeNode* tnode,int a,int b):node(tnode),robbed(a),notRobbed(b){}
};
class Solution {
public:
    int rob(TreeNode* root) {
		if(!root)
			return 0;
		stack<TreeNode*> nodes;
		stack<robbedOrNot*> robValues;
		int result=0;
		TreeNode *hasBeenSearched = NULL;
		nodes.push(root);
		while(!nodes.empty())
		{
			TreeNode* top = nodes.top();
			if(hasBeenSearched&&(top->left==hasBeenSearched||top->right==hasBeenSearched))//time to search top
			{
				if(top->left&&top->right)//two children
				{
					robbedOrNot* child1Value = robValues.top();
					robValues.pop();
					robbedOrNot* child2Value=robValues.top();
					robValues.pop();
					int rvalue = child1Value->notRobbed+child2Value->notRobbed+top->val;
					int notrvalue = max(child1Value->notRobbed,child1Value->robbed)+max(child2Value->notRobbed,child2Value->robbed);
					robbedOrNot* current = new robbedOrNot(top,rvalue,notrvalue);
					robValues.push(current);
					delete child1Value;
					delete child2Value;
					result = max(current->notRobbed,current->robbed);
				}
				else if(top->left || top->right)
				{
					robbedOrNot* child1Value = robValues.top();
					robValues.pop();
					int rvalue = child1Value->notRobbed+top->val;
					int notrvalue = max(child1Value->notRobbed,child1Value->robbed);
					robbedOrNot* current = new robbedOrNot(top,rvalue,notrvalue);
					robValues.push(current);
					delete child1Value;
					result = max(current->notRobbed,current->robbed);
					//cout<<current->notRobbed<<" "<<current->robbed<<endl;
				}
				hasBeenSearched=top;
				nodes.pop();
				delete top;
			}
			else if(top->left&&top->right)//push children
			{
				nodes.push(top->right);
				nodes.push(top->left);
			}
			else if(top->left)			//push child
				nodes.push(top->left);
			else if(top->right)			//push child
				nodes.push(top->right);
			else						//leaves to search
			{
				robbedOrNot *current = new robbedOrNot(top,top->val,0);
				robValues.push(current);
				hasBeenSearched=top;
				nodes.pop();
				delete top;
				result = max(current->notRobbed,current->robbed);
				//cout<<current->notRobbed<<" "<<current->robbed<<endl;
			}
		}
		return result;
    }
};

int main()
{
	Solution *s = new Solution();
	TreeNode *n1=new TreeNode(3);
	TreeNode *n2=new TreeNode(2);
	TreeNode *n3=new TreeNode(3);
	TreeNode *n4=new TreeNode(3);
	TreeNode *n5=new TreeNode(1);
	n1->left=n2;
	n1->right=n3;
	n2->left=n4;
	n3->right=n5;
	cout<<s->rob(n1)<<endl;

}
