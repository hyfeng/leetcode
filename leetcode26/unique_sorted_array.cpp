/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
*/
#include <iostream>
using namespace std;
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=1)return n;
		int i=0,j=1;
		while(j<n){
			if(A[j]!=A[i])A[++i]=A[j];
			++j;
		}
		return i+1;
    }
};
int main(){
	Solution S;
	int a[]={1,1,2};
	int len = S.removeDuplicates(a,3);
	cout<<len<<endl;
	for(int i=0;i<len;++i)cout<<a[i]<<' ';
	cout<<endl;
	system("pause");
	return 0;
}