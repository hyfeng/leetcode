/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL&&l2==NULL)return NULL;
		ListNode head(0);
		ListNode *a = &head;
		while(l1!=NULL&&l2!=NULL){
			if(l1->val<l2->val){
				a->next=l1;
				a = a->next;
				l1=l1->next;
			}
			else{
				a->next=l2;
				a = a->next;
				l2=l2->next;
			}
		}
		while(l1!=NULL){
			a->next = l1;
			a = a->next;
			l1 = l1->next;
		}
		while(l2!=NULL){
			a->next=l2;
			a = a->next;
			l2=l2->next;
		}
		return head.next;
    }
};
int main(){
	return 0;
}