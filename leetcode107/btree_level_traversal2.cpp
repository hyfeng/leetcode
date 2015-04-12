/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/
 //Definition for binary tree
#include <iostream>
#include <cstring>
#include <vector>
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > layer;
		queue<TreeNode*> q;
		int num = 0;
		if(root==NULL)return layer;
		q.push(root);
		++num;
		traverse(layer,q,num);
		return layer;
    }
private:
	void traverse(vector<vector<int> >&layer,queue<TreeNode*> &qu,int num){
		int childs = 0;
		vector<int> level;
		while(num-->0){
			TreeNode* p = qu.front();
			level.push_back(p->val);
			qu.pop();
			if(p->left){
				qu.push(p->left);
				++childs;
			}
			if(p->right){
				qu.push(p->right);
				++childs;
			}
		}
		if(childs>0)traverse(layer,qu,childs);
		layer.push_back(level);
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
void preTrans(TreeNode *root){
	if(root==NULL)return;
	cout<<root->val<<',';
	if(root->left!=NULL){
		preTrans(root->left);
	}
	else{
		cout<<"#"<<',';
	}
	if(root->right!=NULL){
		preTrans(root->right);
	}
	else{
		cout<<"#"<<',';
	}
}
int main(){
	TreeNode * root = createTree("{3,9,2,#,#,5,7}");
	preTrans(root);cout<<endl;
	Solution S;
	vector<vector<int> > la = S.levelOrderBottom(root);

	for(int i=0;i<la.size();++i){
		vector<int>& q = la[i];
		for(int j=0;j<q.size();++j)
			cout<<q[j]<<' ';
		cout<<endl;
	}
	system("pause");
	return 0;
}