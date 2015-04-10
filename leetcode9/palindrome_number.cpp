/*
Determine whether an integer is a palindrome. Do this without extra space.
*/
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
		if(x<0)return false;
		return palindrome(x,x);
    }
	bool palindrome(int x,int &y){
		if(x == 0)return true;
		if(palindrome(x/10,y)&&(x%10) == (y%10)){
			y/=10;
			return true;
		}
		else{
			return false;
		}
	}
};
int main(){
	Solution S;
	bool yes = S.isPalindrome(100021);
	if(yes)cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	system("pause");
	return 0;
}