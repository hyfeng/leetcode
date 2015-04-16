/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int>r;
		int len = numbers.size();
		int half = target/2;
		if(half*2==target){
			int count =0;
			for(int i=0;i<len;++i)
				if(half == numbers[i]){
					r.push_back(i+1);	
					++count;
				}
			if(count ==2 )return r;
			r.clear();
		}
		map<int,int> match;		
		for(int i = 0;i<len;++i){
			if(half!=numbers[i])
				match[target-numbers[i]]++;
		}
		for(int i = 0;i<len;++i){
			if(match.find(numbers[i])!=match.end()){
				int j = 0;
				int rest = target-numbers[i];
				while(j<len){
					if(numbers[j]==rest)break;
					++j;
				}
				int min = i<j?i:j;
				int max = i<j?j:i;
				r.push_back(i+1);
				r.push_back(j+1);
				return r;
			}
		}
    }
};
int main(){
	int a[] = {2, 7, 11, 15};
	vector<int> num(a,a+4);
	Solution S;
	vector<int> r = S.twoSum(num,9);
	for(int i=0;i<r.size();++i)cout<<r[i]<<' ';cout<<endl;
	system("pause");
	return 0;
}