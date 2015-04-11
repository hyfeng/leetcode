/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int> &num) {
		int len = num.size();
		if(len==0)return 0;
		if(len==1)return num[0];
        int *cho = new int[len];
		int *ncho = new int[len];
		cho[0] = num[0];
		ncho[0]=0;
		int i;
		for(i=1;i<len;++i){
			cho[i] = ncho[i-1]+num[i];
			ncho[i]= cho[i-1]<ncho[i-1]?ncho[i-1]:cho[i-1];
		}
		int max = cho[i-1]<ncho[i-1]?ncho[i-1]:cho[i-1];
		delete[]cho;
		delete[]ncho;
		return max;
    }
};
int main(){
	Solution S;
	vector<int> c;
	for(int i=1;i<5;++i)c.push_back(i);
	cout<<S.rob(c)<<endl;
	system("pause");
	return 0;
}