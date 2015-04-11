/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

 //Definition for singly-linked list.
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
		if(n==0)return head;
        ListNode* p = head;
		int len=0;
		while(p!=NULL){
			++len;
			p=p->next;
		}
		if(n==len){
			p = head->next;
			delete head;
			return p;
		}
		p=head;
		for(int i=0;i<len-n-1;++i)p=p->next;
		ListNode *q=p->next;
		p->next=q->next;
		delete q;
		return head;
    }
};
int main(){
	return 0;
}