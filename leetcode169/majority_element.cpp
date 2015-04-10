#include <vector>
#include <iostream>
#include <map>
using std::vector;
using std::map;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        q_sort(num);
		int bfc = 0;
		int bf = 0;
		int curc=1;
		int len = num.size();
		for(int i = 1;i<len;++i){
			if(num[i]==num[i-1])curc++;
			else{
				if(curc>bfc){
					bfc = curc;bf=num[i-1];
				}
				curc=1;
			}
		}
		if(curc>bfc)bf=num[len-1];
		return bf;
    }
	void q_sort(vector<int> &num){
		int flag = 1;
		int len = num.size();
		while(flag){
			flag=0;
			for(int j=0;j<len-1;++j){
				if(num[j]>num[j+1]){
					num[j]^=num[j+1];
					num[j+1]^=num[j];
					num[j]^=num[j+1];
					flag=1;
				}
			}
		}
	}
	int majorityElement2(vector<int> &num) {
		map<int,int> mm;
		map<int,int>::iterator it;
		for(int i=0;i<num.size();++i){
			it = mm.find(num[i]);
			if(it!=mm.end())++(it->second);
			else mm[num[i]]=1;
		}
		int cc = 0;
		int val =0;
		for(it=mm.begin();it!=mm.end();++it){
			if(it->second>cc){
				cc = it->second;
				val = it->first;
			}
		}
		return val;
	}
};
int main(){
	Solution S;
	vector<int> c;
	int v[]={87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78,87,78};
	int n = sizeof(v)/sizeof(int);
	for(int i=0;i<n;++i)c.push_back(v[i]);
	int num = S.majorityElement2(c);	std::cout<<num<<std::endl;
	system("pause");
	return 0;
}