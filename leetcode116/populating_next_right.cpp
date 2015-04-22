/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

//Definition for binary tree with next pointer.
#include <iostream>
using namespace std;
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)return;
		TreeLinkNode * pa = NULL;
		TreeLinkNode *cur = NULL;
		TreeLinkNode *head = root;
		while(head){
			cur = head;
			while(cur){
				if(!pa){
					cur->next =NULL;
				}
				else if(pa->left==cur){
					cur->next = pa->right;
				}
				else{
					pa = pa->next;
					if(pa)cur->next=pa->left;
					else cur->next = NULL;
				}				
				cur = cur->next;
			}///!while(cur)
			pa = head;
			head = pa->left;
		}
    }
};
int main(){

}