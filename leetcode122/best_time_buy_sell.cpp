/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max=0;
		int n = prices.size();		
		int i = 1;
		while(i<n){
			while(i<n&&prices[i]<=prices[i-1])++i;
			if(i==n)break;
			int j = i;
			while(j<n&&prices[j]>=prices[j-1])++j;
			max+= prices[j-1]-prices[i-1];
			i=j;
		}
		return max;
    }
};
int main(){

}