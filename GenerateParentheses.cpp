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

using namespace std;

bool isValid(string s) {

        stack<char> stk;
        for(auto e : s){
            switch(e){
                case '(': stk.push(e); break;
                case '{': stk.push(e); break;
                case '[': stk.push(e); break;

                case ')': {
                    if(stk.empty() || stk.top() != '(')
                        return false;
                    else
                        stk.pop();
                    break;
                }                
                case '}': {
                    if(stk.empty() || stk.top() != '{')
                        return false;
                    else
                        stk.pop();
                        
                    break;
                }                 
                case ']': {
                    if(stk.empty() || stk.top() != '[')
                        return false;
                    else
                        stk.pop();
                    break;
                }
                default: continue;
            }
        }
        return stk.empty();

}

void func(string str, int limited, vector<string> &result){
    if(str.length() >= limited){
        if(isValid("(" + str + ")"))
            result.push_back("(" + str + ")" );
    }else{
        func(str + "(", limited, result);
        func(str + ")", limited, result);
    }
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<string> result;

        int allElementNumber = 2 * n;
        int partOfElementNumber = (allElementNumber - 2);
        func("", partOfElementNumber, result);

        // 1 11 00 0
        //   10 10
        //   01 01
        //   00 11
        return result;
    }
};

int main(int argc, char* argv[]){

    Solution s;

    auto vec = s.generateParenthesis(8);

    for(auto e : vec){
        cout << e << ", "<< endl;
    }

    return 0;
}