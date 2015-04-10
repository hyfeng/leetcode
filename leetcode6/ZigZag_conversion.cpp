/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows<=1)return s;
		int base = 2*nRows-2;
		string re;
		int i=0,len=s.length();
		while(i<len){ //the first line
			re += s[i];
			i += base;
		}
		for(int j=1;j<nRows-1;j++){//the second line to the last but one
			i = 0;
			int k;
			while(i<len){
				k = i+j;
				if(k>=len)break;
				re += s[k];
				i += base;
				k = i-j;
				if(k>=len)break;
				re += s[k];
			}
		}
		i=nRows-1;
		while(i<len){//the last line
			re += s[i];
			i+=base;
		}
		return re;
    }
};
int main(){
	Solution S;
	string re = S.convert("PAYPALISHIRING",3);
	cout<<re<<endl;
	system("pause");
	return 0;
}