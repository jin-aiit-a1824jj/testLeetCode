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

using namespace std;


class Solution {
public:
    //https://leetcode.com/problems/longest-valid-parentheses/discuss/14147/My-simple-8ms-C%2B%2B-code
    int longestValidParentheses(string s) {

       stack<int> stk;
       stak.push(-1);
       int length = 0;

       for(int i = 0; i < s.size(); i++){
           int t = stk.top();

            if( t != -1 && s[i] == ')' && s[t] == '('){
                stk.pop();
                length = max(length, i-stk.top());
            }else{
                stk.push(i);
            }
       }

       return length;
    }
};

int main(int argc, char* argv[]){

    Solution s;
    //string str = "(()()";
    //string str =  "()(()";
    //string str = ")(((((()())()()))()(()))(";
    //string str = "(()))())(";
    //string str = ")()())";
    string str = ")()())";
    cout << s.longestValidParentheses(str) << endl;

    //cout << (isValid(str) ? "true" : "false") << endl;

    return 0;

}