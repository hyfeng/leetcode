/*
Write a function to find the longest common prefix string amongst an array of strings.
*/
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
		int n = strs.size();
		if(n==0)return "";
		int index = strs[0].length();
		for(int i=1;i<n;++i){
			int j;
			for(j=0;j<index&&j<strs[i].length();++j){
				if(strs[0][j]!=strs[i][j])break;
			}
			index = j;
		}
		string prefix;
		for(int i=0;i<index;++i)prefix+=strs[0][i];
		return prefix;
    }
};
int main(){
	return 0;
}