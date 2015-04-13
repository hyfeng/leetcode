/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
		if(n==0||n==1)return 1;
        int x0=1,x1=1;
		int x;
		for(int i=2;i<=n;++i){
			x=x0+x1;
			x0=x1;x1=x;
		}
		return x;
    }
};
int main(){
	Solution S;
	cout<<S.climbStairs(3)<<endl;
	system("pause");
	return 0;

}