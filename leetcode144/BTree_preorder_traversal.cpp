/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/

// Definition for binary tree
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode*> st;
		vector<int> vc;
		if(root==NULL)return vc;
		st.push(root);
		vc.push_back(root->val);
		TreeNode *pre = root;
		while(!st.empty()){
			TreeNode *top = st.top();
			if(pre==top->right||pre==top->left&&top->right==NULL||top->left==NULL&&top->right==NULL){
				st.pop();
				pre=top;
				continue;
			}
			if(pre==top->left||top->left==NULL){
				st.push(top->right);
				vc.push_back(top->right->val);
				continue;
			}
			st.push(top->left);
			vc.push_back(top->left->val);
		}
		return vc;
    }
};
int main(){

}