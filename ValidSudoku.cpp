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

bool isValidLine(const int& i, const int& j, vector<vector<char>>& board){
    const char value = board[i][j];

    int counter = 0;
    for(char row : board[i]){
        //cout << "row[" << row <<"], value[" << value <<"] "; 
        if(row == value)
            counter+=1;
        if(counter > 1)
            return false;
    }

    counter = 0;

    for(char col = 0; col < 9; col++){
        char temp = board[col][j];
        //cout << "temp[" << temp <<"], value[" << value <<"] ";
        if(temp == value)
            counter+=1;
        if(counter > 1)
            return false;
    }

    return true;
}

bool isValidBox(map<char, int>& checker){

    for(int i = 49; i < 58; i++){
        //cout <<  "[" << (char)i << "]->" << checker[i] << endl;
        if(checker[i] > 1){
            return false;
        }
    }
    checker.clear();
    return true;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        map<char, int> checker;
        
        for(int y = 0; y < 3; y++){
                int yMin = 3 * y; // 0 , 3,  6
                int yMax = 3 * y + 3;

            for(int x = 0; x < 3; x++){
            
                int xMin = 3 * x; // 0 , 3,  6
                int xMax = 3 * x + 3;

                for(int i = yMin; i < yMax; i++){
                    for(int j = xMin; j < xMax; j++){
                        //cout << board[i][j] << "   ";
                        if(board[i][j] == '.') continue;
                        checker[board[i][j]] +=1;
                        if(!isValidLine(i,j, board)) return false;
                    }
                    //cout << endl;
                }
                //cout << endl << endl;
                if(!isValidBox(checker))
                    return false;
            }
        }

        return true;
    }
};

int main(int argc, char* argv[]){

    Solution s;

    // vector<vector<char>> board = {
    //     {'5','3','.','.','7','.','.','.','.'},
    //     {'6','.','.','1','9','5','.','.','.'},
    //     {'.','9','8','.','.','.','.','6','.'},
    //     {'8','.','.','.','6','.','.','.','3'},
    //     {'4','.','.','8','.','3','.','.','1'},
    //     {'7','.','.','.','2','.','.','.','6'},
    //     {'.','6','.','.','.','.','2','8','.'},
    //     {'.','.','.','4','1','9','.','.','5'},
    //     {'.','.','.','.','8','.','.','7','9'}
    // };

    vector<vector<char>> board = {
        {'.','.','4','.','.','.','6','3','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'5','.','.','.','.','.','.','9','.'},
        {'.','.','.','5','6','.','.','.','.'},
        {'4','.','3','.','.','.','.','.','1'},
        {'.','.','.','7','.','.','.','.','.'},
        {'.','.','.','5','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.'}
    };



    cout << endl << endl;
    cout << s.isValidSudoku(board) << endl;

    return 0;

}