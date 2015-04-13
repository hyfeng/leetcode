/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
		int i = digits.size()-1;
		int d=1;
		while(i>=0){
			int val = digits[i]+d;
			digits[i--]=val%10;
			d=val/10;
			if(d==0)break;
		}
		if(d>0){
			digits.insert(digits.begin(),d);
		}
		return digits;
    }
};
int main(){
	vector<int> a;
	for(int i=1;i<=9;++i){
		a.push_back(i);
	}
	for(int i=0;i<a.size();++i)cout<<a[i]<<' ';cout<<endl;
	Solution S;
	a = S.plusOne(a);
	for(int i=0;i<a.size();++i)cout<<a[i]<<' ';cout<<endl;
	system("pause");
	return 0;
}