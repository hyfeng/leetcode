/*
*mplement atoi to convert a string to an integer.
*/
#include <string>
#include <iostream>
using std::string;

class Solution {
public:
    int atoi(string str) {
		int len = str.length();
		int i = 0;
		int num = 0;
		int flag = 0;
		//delete front zero
		while(i<len&&str[i]==' ')++i;
		if(i==len)return 0;
		if(str[i]=='-')flag=1;
		if(flag==1||str[i]=='+')++i;
		while(i<len){
			if(str[i]<'0'||str[i]>'9')break;
			if(num != num*10/10){
				if(flag==1)return INT_MIN;
				return INT_MAX;
			}
			num *= 10;
			num += str[i]-'0';
			++i;
		}
		if(flag==1){
			if(num<0)return INT_MIN;
			return -num;
		}
		if(num<0)return INT_MAX;
		return num;
    }
};
int main(){
	Solution S;
	std::cout<<S.atoi("2147483648")<<std::endl;
	system("pause");
	return 0;
}