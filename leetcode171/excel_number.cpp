#include <string>
#include <iostream>
using std::string;

class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
		for(int i=0;i<s.length();i++){
			sum *= 26;
			sum += s[i]-'A'+1;
		}
		return sum;
    }
};
int main(){
	string s = "AB";
	Solution S;
	int code = S.titleToNumber(s);
	std::cout<<code<<std::endl;
	system("pause");
	return 0;
}