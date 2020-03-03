#include <iostream>   // std::cout, std::endl;
#include <algorithm>  // std::sort, std::unique
#include <vector>     // std::vector
#include <stdio.h>    // printf
#include <map>
#include <queue>
#include <string.h> //strcmp、strncmp関数を使うために必要
#include <stdexcept>
#include <climits>
#include <sstream> // std::stringstream
#include <istream> // std::getline
#include <regex>
#include <unordered_set>
#include <stack>
#include <functional> // std::divides 
#include <iterator>

using namespace std;

//https://qiita.com/Anishishi/items/00fa13fcf0850144cae1

bool check_vertically(vector< vector<char> >& arr, int x, char n)//縦の確認
{
    for(int i=0 ; i<9 ; i++){
        if( arr[i][x] == n){
            return false;
        }
    }
    return true;
}

bool check_horizontally(vector< vector<char> >& arr, int y, char n)//横の確認
{
    for(int i=0 ; i<9 ; i++){
        if( arr[y][i] == n){
            return false;
        }
    }
    return true;
}
bool check_mass(vector< vector<char> >& arr, int x, int y, char n)//3*3マスでの確認
{
    int x_base=(x/3)*3;
    int y_base=(y/3)*3;
    for(int i=x_base; i<x_base+3; i++){
        for(int j=y_base; j<y_base+3; j++){
            if( arr[j][i] == n){
                return false;
            }
        }
    }
    return true;
}
char change_num(vector< vector<char> >& arr, int x, int y, char n)//n:1~9での置き換えを試みるダメなら0を返す
{
    if(check_vertically(arr, x, n)==1 && check_horizontally(arr, y, n)==1 && check_mass(arr, x, y, n)==1){
        return arr[y][x] = n;
    }else{
        return '.';
    }
}

bool solve_sudoku(vector< vector<char> >& arr, int x, int y)//x:0~8、横方向,y:0~8、縦方向
//深さ優先探索
{
    if(y>8){
        return true;
    }else if(x>8){
        if(solve_sudoku(arr, 0, y+1)==1){
            return true;
        }
    }else if(arr[y][x]!='.'){
        if(solve_sudoku(arr, x+1, y)==1){
            return true;
        }
    }else{
        for(int i=49; i<=57; i++){//iを当てはめていく
            char tmp = change_num(arr, x, y, (char)i);
            if(tmp != '.' ){
                if(solve_sudoku(arr, x+1, y)==1){
                    return true;
                }
            }
        }
        arr[y][x]='.';
    }
    
    return false;
}

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        solve_sudoku(board, 0, 0);

        for(int y = 0; y < 7; y+=3){
                int yMin = y; // 0 , 3,  6
                int yMax = y + 3;
            for(int x = 0; x < 7; x+=3){
                int xMin = x; // 0 , 3,  6
                int xMax = x + 3;

                for(int i = yMin; i < yMax; i++){
                    for(int j = xMin; j < xMax; j++){
                        cout << board[i][j] << "   ";
                        //if(board[i][j] == '.') continue;
                        //checker[board[i][j]] +=1;
                       
                    }
                    cout << endl;
                }
                cout << endl << endl;

            }
        }


    }
};

int main(int argc, char* argv[]){

    Solution s;

    vector<vector<char>> board = 
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };


    s.solveSudoku(board);

    return 0;

}