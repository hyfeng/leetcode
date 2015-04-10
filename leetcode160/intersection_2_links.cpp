/*
Write a program to find the node at which the intersection of two singly linked lists begins.
A:          a1 ¡ú a2
                   ¨K
                     c1 ¡ú c2 ¡ú c3
                   ¨J            
B:     b1 ¡ú b2 ¡ú b3
Definition for singly-linked list.
*/
#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena=0,lenb=0;
		ListNode * p = headA;
		ListNode *q;
		while(p!=NULL){
			p=p->next;
			++lena;
		}
		p=headB;
		while(p!=NULL){
			p=p->next;
			++lenb;
		}
		p=headA;
		q=headB;
		while(lena>lenb){
			p=p->next;
			--lena;
		}
		while(lena<lenb){
			q=q->next;
			--lenb;
		}
		while(p!=q){
			p=p->next;
			q=q->next;
		}
		return p;
    }
};
int main(){

}