/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s);
		int last = 0;
		int count = 0;
		bool word = true;
		for(int i = 0;i<len;++i){
			if(word){
				if(s[i]==' '){
					word=false;
					last=count;
					count=0;
				}
				else ++count;									
			}
			else if(s[i]!=' '){
				word=true;
				++count;
			}
		}
		if(word)last=count;
		return last;
    }
};
int main(){
	Solution S;
	cout<<S.lengthOfLastWord("Helo World ")<<endl;
	system("pause");
	return 0;
}