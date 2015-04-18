/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode head(0);
		ListNode *t = &head;
		ListNode *p=l1,*q=l2;
		int d=0;
		while(p&&q){
			int sum = p->val+q->val+d;
			p=p->next;
			q=q->next;
			ListNode* v = new ListNode(sum%10);
			t->next=v;
			d = sum/10;
			t=v;
		}
		while(d&&p){
			int sum = p->val+d;
			p=p->next;
			ListNode *v = new ListNode(sum%10);
			t->next=v;
			d = sum/10;
			t=v;
		}
		while(d&&q){
			int sum = q->val+d;
			q=q->next;
			ListNode *v = new ListNode(sum%10);
			t->next=v;
			d = sum/10;
			t=v;
		}
		if(p)t->next=p;
		else if(q)t->next=q;
		if(d){
			ListNode *v = new ListNode(d);
			t->next=v;
		}
		return head.next;
    }
};