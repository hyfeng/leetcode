/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/
//  Definition for binary tree
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root==NULL)return 0;
		if(root->left==NULL&&root->right==NULL)return 1;
		int l = 0,r=0;
		if(root->left)l=maxDepth(root->left);
		if(root->right)r=maxDepth(root->right);
		return (l<r?r:l)+1;
    }
};
TreeNode* createTree(char *seri){
	int len = strlen(seri);
	if(len<3)return NULL;
	TreeNode* root = new TreeNode(seri[1]-'0');
	if(len==3)return root;
	queue<TreeNode*> qu;
	qu.push(root);
	for(int i=3;i<len-1;i+=2){
		TreeNode * p = qu.front();
		qu.pop();
		if(seri[i]!='#'){//left
			TreeNode *q = new TreeNode(seri[i]-'0');
			p->left=q;
			qu.push(q);
		}
		i+=2;
		if(seri[i]!='#'){
			TreeNode *q = new TreeNode(seri[i]-'0');
			p->right=q;
			qu.push(q);
		}
	}
	return root;
}
int main(){
	TreeNode* root = createTree("{3,9,2,#,#,5,7}");
	Solution S;
	cout<<S.maxDepth(root)<<endl;
	system("pause");
	return 0;
}