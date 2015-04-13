/*
Determine if a Sudoku is valid
The Sudoku board could be partially filled, where empty cells are filled with the character '.'
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int count[27][9];
		memset(count,0,sizeof(int)*27*9);
		for(int j=0;j<9;++j){
			vector<char> temp = board[j];
			for(int i=0;i<9;++i){
				if(temp[i]=='.')continue;
				int val = temp[i]-'0';
				count[j][val]++;
				count[i+9][val]++;
				count[i/3+j/3*3+18][val]++;
			}
		}
		for(int i=0;i<27;++i){
			for(int j=0;j<9;++j){
				if(count[i][j]>1)return false;
			}
		}
		return true;
    }
};
int main(){

}