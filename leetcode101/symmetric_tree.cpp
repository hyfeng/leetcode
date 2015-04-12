/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
*/
//  Definition for binary tree
#include <iostream>
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
    bool isSymmetric(TreeNode *root) {
        if(root==NULL)return true;
		vector<TreeNode*> *level = new vector<TreeNode*>();
		level->push_back(root);
		return level_traversal(level);
    }
private:
	bool level_traversal(vector<TreeNode*> *preLevel){
		vector<TreeNode* >*level = new vector<TreeNode*>();
		for(int i = 0;i<preLevel->size();++i){
			if((*preLevel)[i]==NULL)continue;
			level->push_back((*preLevel)[i]->left);
			level->push_back((*preLevel)[i]->right);
		}
		delete preLevel;
		if(level->empty()){
			delete level;
			return true;
		}
		int size = level->size();
		int i = 0;
		for(i= 0;i<size/2;++i){
			if(((*level)[i]==NULL||(*level)[size-i-1]==NULL)&&(*level)[i]!=(*level)[size-i-1])break;
			if((*level)[i]!=NULL&&(*level)[size-i-1]!=NULL&&(*level)[i]->val!=(*level)[size-i-1]->val)break;
		}
		if(i<size/2){
			delete level;
			return false;
		}
		return level_traversal(level);
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
	TreeNode* root = createTree("{1,#,2,3,4,4,3}");
	Solution S;
	bool yes = S.isSymmetric(root);
	if(yes)cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	system("pause");
	return 0;
}