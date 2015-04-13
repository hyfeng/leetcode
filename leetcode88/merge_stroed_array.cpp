/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
*/
#include <iostream>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int k =m+n-1;
		int i = m-1,j=n-1;
		while(i>=0&&j>=0){
			if(A[i]>B[j]){
				A[k--]=A[i--];
			}
			else{
				A[k--]=B[j--];
			}
		}
		while(j>=0){
			A[k--]=B[j--];
		}
    }
};
int main(){
	int a[7]={1,2,5,7};
	int b[3]={3,4,6};
	Solution S;
	S.merge(a,4,b,3);
	for(int i=0;i<7;++i){
		cout<<a[i]<<' ';
	}
	cout<<endl;
	system("pause");
	return 0;
}