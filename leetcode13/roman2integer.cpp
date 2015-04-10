/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
		int i = s.length()-1;		
		int num = 0;
		while(i>0){
			int cur = get_roman(s[i]);
			int pre = get_roman(s[i-1]);
			if(pre>=cur){
				num+=cur;
				--i;
			}
			else{
				num += cur-pre;
				i-=2;
			}
		}
		if(i==0)num+=get_roman(s[i]);
		return num;
    }
private:
	int get_roman(char Rm){
		switch(Rm){
		case 'I':return 1;
		case 'V':return 5;
		case 'X':return 10;
		case 'L':return 50;
		case 'C':return 100;
		case 'D':return 500;
		default:return 1000;
		}
	}
};
int main(){
	Solution S;
	cout<<S.romanToInt("MMMCMXCIX")<<endl;
	system("pause");
	return 0;
}