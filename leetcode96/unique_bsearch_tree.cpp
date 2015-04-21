/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
class Solution {
public:
    int numTrees(int n) {
        int *d = new int[n+1];
		d[0]=1;
		d[1]=1;
		d[2]=2;
		for(int i=3;i<=n;++i){
			int l = 0,r=i-1;
			int sum = 0 ;
			while(l<r){
				sum+=d[l]*d[r]*2;
				++l;--r;
			}
			if(l==r)sum+=d[l]*d[l];
			d[i]=sum;
		}
		return d[n];
    }
};