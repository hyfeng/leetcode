#include <iostream>

class Solution {
public:
    void rotate(int nums[], int n, int k) {
		k%=n;
		if(k<=0)return;
		reverse(nums,0,n);
		if(k>=n)return;
		reverse(nums,0,k);
		reverse(nums,k,n);
    }
	void reverse(int nums[],int l,int r){
		r--;
		while(l<r){
			nums[l]^=nums[r];
			nums[r]^=nums[l];
			nums[l]^=nums[r];
			l++;
			r--;
		}
	}
};
int main(){
	int a[] = {1,2,3,4,5,6,7};
	Solution s ;
	s.rotate(a,7,3);
	for(int i = 0;i<7;i++){
		std::cout<<a[i]<<" ";
	}
	std::cout<<std::endl;
	system("pause");
	return 0;
}