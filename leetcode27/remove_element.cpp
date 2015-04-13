/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
		while(i<n){
			if(A[i]==elem)A[i]=A[--n];
			else ++i;
		}
		return n;
    }
};
int main(){
	int a[]={3,5,4,7,1,10};
	Solution S;
	int len=S.removeElement(a,6,7);
	for(int i=0;i<len;++i){
		cout<<a[i]<<' ';
	}
	cout<<endl;
	system("pause");
	return 0;
}