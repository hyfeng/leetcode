/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree 
in which the depth of the two subtrees of every node never differ by more than 1.
*/

  //Definition for binary tree
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
    bool isBalanced(TreeNode *root) {
		if(root==NULL)return true;
		int h;
		return hiBalance(root,h);
    }
	bool hiBalance(TreeNode *root,int& hei){
		if(root==NULL){
			hei=0;
			return true;
		}
		int lh,rh;
		if(hiBalance(root->left,lh)&&hiBalance(root->right,rh)){
			int maxh,minh;
			if(lh>rh){
				maxh=lh;minh=rh;
			}
			else{
				maxh=rh;minh=lh;
			}
			if(maxh-minh>1)return false;
			else{
				hei=maxh+1;
				return true;
			}
		}
		return false;
	}
};

int main(){
	return 0;
}
