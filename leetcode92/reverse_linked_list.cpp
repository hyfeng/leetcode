/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list.
*/

// Definition for singly-linked list.
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode pre(0);
		pre.next=head;
		ListNode *p=&pre;
		for(int i = 0;i<m-1;++i)p=p->next;
		ListNode *q = p->next;
		for(int i=0;i<n-m;++i){
			ListNode *t = q->next->next;
			q->next->next = p->next;
			p->next = q->next;
			q->next = t;
		}
		return pre.next;
    }
};
ListNode *create(int d[],int n){
	ListNode *root = new ListNode(d[0]);
	ListNode *p=root;
	for(int i=1;i<n;++i){
		ListNode * t = new ListNode(d[i]);
		p->next=t;
		p=p->next;
	}
	return root;
}
int main(){
	int d[]={1,2,3,4,5};
	ListNode* root = create(d,5);
	ListNode *p=root;
	while(p){cout<<p->val<<' ';p=p->next;}cout<<endl;
	Solution S;
	ListNode *t = S.reverseBetween(root,2,4);
	p = t;
	while(p){cout<<p->val<<' ';p=p->next;}cout<<endl;
	system("pause");
	return 0;
}