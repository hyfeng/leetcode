/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string r;
		int i=a.length()-1;
		int j=b.length()-1;
		int d =0;
		while(i>=0&&j>=0){
			int sum = a[i]+b[j]-'0'*2+d;
			r+=sum%2+'0';
			d=sum/2;
			--i;
			--j;
		}
		while(i>=0){
			int sum = a[i]+d-'0';
			r+=sum%2+'0';
			d=sum/2;
			--i;
		}
		while(j>=0){
			int sum =b[j]-'0'+d;
			r+=sum%2+'0';
			d=sum/2;
			--j;
		}
		if(d==1)r+='1';
		int len = r.length();
		for(int i=0;i<len/2;++i){
			r[i]^=r[len-1-i];
			r[len-1-i]^=r[i];
			r[i]^=r[len-1-i];
		}
		return r;
    }
};
int main(){
	Solution S;
	cout<<S.addBinary("11","1")<<endl;
	system("pause");
	return 0;
}