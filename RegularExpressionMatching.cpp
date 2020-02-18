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
    bool isMatch(string s, string p) {
        regex re(p);
        smatch match; 
        return regex_match(s, match, re);
    }
};


int main(int argc, char* argv[]){
    Solution s;
    cout << (bool)s.isMatch("s", "p") << endl;
    return 0;
}