/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
		return haystack.find(needle);
    }
};
int main(){
	Solution S;
	cout<<S.strStr("abcd","cd")<<endl;
	system("pause");
	return 0;
}