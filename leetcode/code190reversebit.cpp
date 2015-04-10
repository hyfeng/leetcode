#include <iostream>
typedef unsigned int uint32_t;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
		uint32_t re = 0;
		for(int i=0;i<32;i++){
			re <<= 1;
			if((n&1) ==  1){
				re |= 1;
			}
			n>>=1;
		}
		return re;
    }
};
int main(){
	Solution s;
	std::cout<<s.reverseBits(43261596u)<<std::endl;
	system("pause");
	return 0;
}
