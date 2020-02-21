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

class Solution {
public:
/*
    bool isValid(string s) {

        sort(s.begin(), s.end());
        
        int a40 = 0;
        int a41 = 0;

        vector<int> v_a40;
        vector<int> v_a41;

        int b123 = 0;
        int b125 = 0;

        vector<int> v_b123;
        vector<int> v_b125;

        int c91 = 0;
        int c93 = 0;

        vector<int> v_c91;
        vector<int> v_c93;

        bool isOpen = false;
        char savedOpenChar = 0;
        int counter = 0;

        for(auto e: s){

            if(e == '('){
                a40 += 1;
                isOpen = true;
                savedOpenChar = e;
                continue;
            }

            if(e == '{'){
                b123 += 1;
                isOpen = true;
                savedOpenChar = e;
                continue;
            }

            if(e == '['){
                c91 += 1;
                isOpen = true;
                savedOpenChar = e;
                continue;
            }

            if(e == ')'){
                a41 += 1;
                if(isOpen){
                    if(savedOpenChar != '(')
                        return false;
                    else
                        isOpen = false;
                }
                continue;
            }


            if(e == '}'){
                b125 += 1;
                if(isOpen){
                    if(savedOpenChar != '{')
                        return false;
                    else
                        isOpen = false;
                }
                continue;
            }

        
            if(e == ']'){
                c93 += 1;
                if(isOpen){
                    if(savedOpenChar != '[')
                        return false;
                    else
                        isOpen = false;
                }
                continue;
            }

        }

        if( a40 != a41) return false;
        if( b123 != b125) return false;
        if( c91 != c93) return false;
        
        return true;
    }
*/

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


};

int main(int argc, char* argv[]){
    
    // cout << (int)'(' << endl;
    // cout << (int)')' << endl;
    // cout << (int)'{' << endl;
    // cout << (int)'}' << endl;
    // cout << (int)'[' << endl;
    // cout << (int)']' << endl;





    Solution s;
    //string a = "()[]{}";
    
    string a = "[ ( {(())}[()] ) ]";
    string a = "    {(())} [()]    ";

    

    cout << " -> " << a << " <-  ==> " << s.isValid(a) << endl;

    
    return 0;
}