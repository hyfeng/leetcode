/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

 // Definition for binary tree
#include <iostream>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(root==NULL){
			return false;
		}
		int value = sum - root->val;
		if(value==0&&root->left==NULL&&root->right==NULL)return true;
		return hasPathSum(root->left,value)||hasPathSum(root->right,value);
    }
};
int main(){

	return 0;
}