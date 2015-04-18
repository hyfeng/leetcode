/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode *swapPairs(ListNode *head) {
		ListNode h(0);
		h.next = head;
        ListNode *p = &h;
		ListNode *q = p->next;
		while(q&&q->next){
			p->next = q->next;
			q->next = q->next->next;
			p->next->next = q;
			p = p->next->next;
			q = p->next;
		}
		return h.next;
    }
};
int main(){

}