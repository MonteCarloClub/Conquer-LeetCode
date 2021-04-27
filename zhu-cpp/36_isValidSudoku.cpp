//
// Created by Oliver on 2021/4/27.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char,int>R[10];
        map<char,int>C[10];
        map<char,int>B[10];
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(board[i][j]!='.')
                    if(R[i][board[i][j]]!=0||C[j][board[i][j]]!=0||B[i/3+j/3*3][board[i][j]]!=0)
                    return false;
                    else R[i][board[i][j]]=C[j][board[i][j]]=B[i/3+j/3*3][board[i][j]]=1;
        return true;
    }
};

int main()
{
    vector<vector<char>> board ={{'8','3','.','.','7','.','.','.','.'}
            ,{'6','.','.','1','9','5','.','.','.'}
            ,{'.','9','8','.','.','.','.','6','.'}
            ,{'8','.','.','.','6','.','.','.','3'}
            ,{'4','.','.','8','.','3','.','.','1'}
            ,{'7','.','.','.','2','.','.','.','6'}
            ,{'.','6','.','.','.','.','2','8','.'}
            ,{'.','.','.','4','1','9','.','.','5'}
            ,{'.','.','.','.','8','.','.','7','9'}};

    Solution s;
    cout<<s.isValidSudoku(board);
    return 1;
}