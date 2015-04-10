#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
		int i=0,j=0;
		int len1=version1.length();
		int len2=version2.length();
		while(1){
			int num1=0,num2=0;
			while(i<len1&&version1[i]!='.'){
				num1*=10;
				num1+=version1[i++]-'0';
			}
			while(j<len2&&version2[j]!='.'){
				num2*=10;
				num2+=version2[j++]-'0';
			}
			if(num1<num2)return -1;
			if(num1>num2)return 1;
			if(i>=len1&&j>=len2)return 0;
			++i;++j;
		}
    }
};
int main(){
	Solution S;
	int code = S.compareVersion("1","1.1");
	cout<<code<<endl;
	system("pause");
	return 0;
}