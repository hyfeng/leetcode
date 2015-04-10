#include <vector>
#include <iostream>
using std::vector;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> store;
		store.push_back(1);
		int cul =1;
		for(int i = 1;i<=rowIndex/2;++i){
			int nm = rowIndex-i+1;
			int g = gcd(nm,i);
			cul /= i/g;
			cul *= nm/g;
			store.push_back(cul);
		}
		int j=rowIndex/2;
		if(rowIndex%2==0)--j;
		while(j>=0){
			store.push_back(store.at(j--));
		}
		return store;
    }
	int gcd(int a,int b){
		int c = a%b;
		while(c!=0){
			a=b;b=c;
			c = a%b;
		}
		return b;
	}
};
int main(){
	Solution S;
	std::cout<<S.gcd(50,30)<<std::endl;
	vector<int> st = S.getRow(13);
	for(int i = 0;i<st.size();++i){
		std::cout<<st.at(i)<<" ";
	}
	std::cout<<std::endl;
	system("pause");
	return 0;
}