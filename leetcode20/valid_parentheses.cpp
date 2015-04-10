/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
		int len = s.length();
		char *stack = new char[len/2];
		int j=-1;
		for(int i=0;i<len;++i){
			char tt = s[i];
			if(tt=='('||tt=='{'||tt=='[')stack[++j]=tt;
			else if(j==-1||tt==')'&&'('!=stack[j]||tt==']'&&stack[j]!='['||tt=='}'&&stack[j]!='{')
				return false;
			else {
				--j;
			}
		}
		delete[] stack;
		if(j==-1)return true;
		return false;
    }
};
int main(){
	Solution S;
	bool sig = S.isValid("(}[)");
	if(sig)cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	system("pause");
	return 0;
}