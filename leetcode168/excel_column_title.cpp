#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string re;
		while(n--){
			re += 'A'+n%26;
			n /= 26;
		}
		int len=re.length();
		for(int i=0;i<len/2;++i){
			re[i]^=re[len-1-i];
			re[len-1-i]^=re[i];
			re[i]^=re[len-1-i];
		}
		return re;
    }
};
int main(){
	Solution S;
	string s = S.convertToTitle(28);
	cout<<s<<endl;
	system("pause");
	return 0;
}