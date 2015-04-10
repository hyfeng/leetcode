#include <string>
#include <iostream>
using std::string;

class Solution {
public:
    string countAndSay(int n) {
		string in = "1";
		for(int i=0;i<n-1;++i){
			string temp;
			int count = 1;int len = in.length();
			for(int j = 1;j<len;++j){
				if(in[j]==in[j-1])count++;
				else{
					temp += count+'0';
					temp += in[j-1];
					count = 1;
				}
			}
			temp += count+'0';
			temp += in[len-1];
			in = temp;
		}
		return in;
    }
};
int main(){
	Solution S;
	string out = S.countAndSay(5);
	std::cout<<out<<std::endl;
	system("pause");
	return 0;
}