/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vc;
		string temp = "";
		gen(vc,temp,0,2*n);
		return vc;
    }
private:void gen(vector<string> &vc,string temp,int sum,int n){
		if(n==1){
			vc.push_back(temp+')');
			return;
		}
		if(sum<n)
			gen(vc,temp+'(',sum+1,n-1);
		if(sum>0)
			gen(vc,temp+')',sum-1,n-1);
	}
};
int main(){
	Solution S;
	vector<string> vc = S.generateParenthesis(3);
	for(int i=0;i<vc.size();i++){
		cout<<vc[i]<<endl;
	}
	system("pause");
	return 0;
}