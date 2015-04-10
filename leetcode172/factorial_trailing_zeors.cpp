#include <iostream>

class Solution {
public:
    int trailingZeroes(int n) {
		int num = 0;
		while(n>0){ // 5,5^2,5^3出现的次数
			num+= n/5;
			n/=5;
		}
		return num;
	}
};
int main(){
	Solution S;
	std::cout<<S.trailingZeroes(10)<<std::endl;
	system("pause");
	return 0;
}