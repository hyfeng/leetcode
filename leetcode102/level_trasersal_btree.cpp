/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

 //Definition for binary tree 
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> >layer;
		if(root==NULL)return layer;
		queue<TreeNode*> qu;
		qu.push(root);
		int num=1;
		while(!qu.empty()){
			int count = 0;
			vector<int> *level = new vector<int>();
			while(num-->0){
				TreeNode* p = qu.front();
				qu.pop();
				level->push_back(p->val);
				if(p->left){
					qu.push(p->left);
					++count;
				}
				if(p->right){
					qu.push(p->right);
					++count;
				}
			}
			layer.push_back(*level);
			num = count;
		}
		return layer;
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
	vector<vector<int> > la = S.levelOrder(root);

	for(int i=0;i<la.size();++i){
		vector<int>& q = la[i];
		for(int j=0;j<q.size();++j)
			cout<<q[j]<<' ';
		cout<<endl;
	}
	system("pause");
	return 0;
}