/*
Write a function that takes an unsigned integer and returns the number of ��1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ��11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/
#include <iostream>
using namespace std;
typedef unsigned int uint32_t;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
		while(n){
			if(n&1)++count;
			n>>=1;
		}
		return count;
    }
};
int main(){
	Solution S;
	cout<<S.hammingWeight(25u)<<endl;
	system("pause");
	return 0;
}