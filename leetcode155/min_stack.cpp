/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/
#include <stack>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class MinStack {
private:
	stack<int> st;
	vector<int> min;
	map<int,int>project;
public:
    void push(int x) {
		st.push(x);
		min.push_back(x);
		int i;
		for(i = min.size()-2;i>=0;--i){
			if(x<min[i])min[i+1]=min[i];
			else break;
		}
		min[i+1]=x;
		project[x]=i+1;
    }

    void pop() {
		if(st.empty())return;
		int x = st.top();
		st.pop();
		int index = project[x];
		project[x] = index-1;
		for(int i=index;i<min.size()-1;++i)min[i]=min[i+1];
		min.erase(min.end()-1);
    }

    int top() {
		return st.top();
    }

    int getMin() {
		return min.at(0);
    }
};
int main(){
	MinStack st;
	st.push(2);
	st.push(3);
	st.pop();
	st.push(1);
	st.push(6);
	st.pop();
	st.push(7);
	cout<<st.getMin()<<endl;

	system("pause");
}