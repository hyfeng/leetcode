/*
Given a binary tree, find its minimum depth.
*/
//Definition for binary tree
#include <iostream>
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
    int minDepth(TreeNode *root) {
        if(root==NULL)return 0;
		if(root->left==NULL&&root->right==NULL)return 1;
		int min=0;
		if(root->left)min = minDepth(root->left);
		if(root->right){
			int r = minDepth(root->right);
			if(min==0)min=r;
			else if(r<min)min=r;
		}
		return min+1;
    }
	int minDepth2(TreeNode *root){
		if(root==NULL)return 0;
		stack<TreeNode*> st;
		st.push(root);
		TreeNode *pre = root;
		int layer = 1;
		int min_layer=INT_MAX;
		while(!st.empty()){
			TreeNode *cur = st.top();
			if(cur->left==NULL&&cur->right==NULL){
				if(min_layer>layer)min_layer=layer;
				st.pop();
				--layer;
				pre = cur;
			}
			else if(cur->right!=NULL&&pre==cur->right||cur->right==NULL&&pre == cur->left){
				st.pop();
				--layer;
				pre = cur;
			}
			else if(cur->left!=NULL&&pre == cur->left){
				st.push(cur->right);
				++layer;
			}else if(cur->left!=NULL){
				st.push(cur->left);
				++layer;
			}
			else {
				st.push(cur->right);
				++layer;
			}
		}
		return min_layer;
	}
};

int main(){
	return 0;
}