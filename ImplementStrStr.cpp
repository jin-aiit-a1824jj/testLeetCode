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
    int strStr(string haystack, string needle) {
        if(needle.size() == 0){
            return 0;
        }
        if(haystack.size() < needle.size()){
            return -1;
        }
        return haystack.find(needle);
    }
};

int main(int argc, char* argv[]){
    
    Solution s;
    string haystack = "hello";
    string needle = "ll";
    cout << s.strStr(haystack, needle) << endl;
    return 0;

}
