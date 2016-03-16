#include<iostream>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
		ListNode* oddTail=NULL,*evenHead=NULL;
		if(head&&head->next&&head->next->next)
		{
			ListNode* tmp=head->next;
			head->next=tmp->next;
			tmp->next = head->next->next;
			head->next->next=tmp;
			oddTail=head->next;
			evenHead=head->next->next;
		}
		else
			return head;
		int num=4;
		ListNode *pre=evenHead,*cur=evenHead->next;
		while(cur)
		{
			if(num%2==1)//odd,need to rotate
			{
				ListNode* temp=cur;
				pre->next=cur->next;
				oddTail->next=temp;
				temp->next=evenHead;
				oddTail=oddTail->next;
				cur=pre->next;
			}
			else		//even,continue;
			{
				pre=pre->next;
				cur=cur->next;
			}
			num++;
		}
		return head;
    }
};
int main()
{
	Solution s;
	ListNode *a1 = new ListNode(1),*a2 = new ListNode(2),*a3 = new ListNode(3),*a4 = new ListNode(4),*a5 = new ListNode(5),*a6 = new ListNode(6);
	a1->next=a2;
	a2->next=a3;
	a3->next=a4;
	a4->next=a5;
	a5->next=a6;
	ListNode* result = s.oddEvenList(a1);
	while(result)
	{
		cout<<result->val<<endl;
		result=result->next;
	}
	return 0;
}
