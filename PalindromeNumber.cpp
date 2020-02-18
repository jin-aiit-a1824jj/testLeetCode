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
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);

        if(str.length() == 1)
            return true;
        
        if(str[0] == '-')
            return false;
        
        if(str[str.length()-1] == '0')
            return false;

        for(int i = 0; i < str.length(); i ++){
            if(str[i] != str[str.length()-1-i]){
                return false;
            }
        }
        return true;
    }
};


int main(int argc, char* argv[]){
    Solution s;
    cout << (bool)s.isPalindrome(123) << endl;


    return 0;
}