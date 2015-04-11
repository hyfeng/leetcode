/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > layer;
		if(numRows==0)return layer;
		vector<int> *temp = new vector<int>();
		temp->push_back(1);
		layer.push_back(*temp);
		vector<int> * up = temp;
		for(int i=1;i<numRows;++i){
			temp = new vector<int>();
			temp->push_back(1);
			for(int j=1;j<up->size();++j){
				temp->push_back((*up)[j-1]+(*up)[j]);
			}
			temp->push_back(1);
			up=temp;
			layer.push_back(*temp);
		}
		return layer;
    }
};
int main(){
	Solution S;
	vector<vector<int> > c = S.generate(5);
	for(int i=0;i<c.size();++i){
		vector<int> &t = c[i];
		for(int j=0;j<t.size();++j){
			cout<<t[j]<<' ';
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}