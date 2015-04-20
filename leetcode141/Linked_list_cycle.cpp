/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

//  Definition for singly-linked list.
#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    bool hasCycle(ListNode *head) {
		if(head==NULL||head->next==NULL)return false;
		ListNode *f = head->next;
		ListNode *l = head;
		while(f!=NULL&&f->next!=NULL&&f!=l){
			f=f->next->next;
			l=l->next;
		}
		if(f==NULL||f->next==NULL)return false;
		return true;
    }
};
int main(){

}