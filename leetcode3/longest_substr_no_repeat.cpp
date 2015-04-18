/*
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int size = s.length();
		if(size==0)return 0;
        int l = 0;
		int max = 0;
		int len =1;
		for(int j=1;j<size;++j){
			int i = j-1;
			char cur = s[j];
			while(i>l-1){
				if(s[i]==cur)break;
				--i;
			}
			if(i==l-1){
				++len;
			}
			else{
				if(len>max){
					max = len;
				}
				len = j-i;
				l = i+1;
			}
		}
		if(len>max)max=len;
		return max;
    }
};
int main(){
	Solution S;
	cout<<S.lengthOfLongestSubstring("bbbbb")<<endl;
	system("pause");
	return 0;
}