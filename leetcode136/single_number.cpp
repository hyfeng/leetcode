/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
#include <iostream>
using namespace std;
class Solution {
public:
    int singleNumber(int A[], int n) {
		while(--n>0)A[0]^=A[n];
		return A[0];
    }
};
int main(){
	int a[]={1};
	Solution S;
	int r = S.singleNumber(a,sizeof(a)/sizeof *a);
	cout<<r<<endl;
	system("pause");
	return 0;
}