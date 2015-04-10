/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/
#include <iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int d = x<0?-x:x;
		int re = 0;
		while(d>0){
			if(re != re*10/10)return 0;
			re *= 10;
			re += d%10;
			d/=10;
		}
		if(x<0)re=-re;
		return re;
    }
};
int main(){
	Solution S;
	cout<<S.reverse(1563847412)<<endl;
	system("pause");
	return 0;
}