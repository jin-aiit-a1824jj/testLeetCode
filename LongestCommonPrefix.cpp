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
    string longestCommonPrefix(vector<string>& strs) {
        
        string c = "";

        if(strs.size() == 0) return c;
        if(strs.size() == 1) return strs[0];
        if(strs[0] == "") return c;

        for(int i = 1; i <= strs[0].length(); i++){
            c = strs[0].substr(0,i);
            bool isOver = false;
            for(auto e: strs){
                if(e.find(c) == string::npos){
                    c = c.substr(0, c.length()-1);
                    isOver = true;
                    break; 
                }
            }
            if(isOver)
                break;
        }

        cout << c << endl;

        int pos = strs[0].find(c);

        cout << pos << endl;

        for(int i = 0; i < strs.size(); i++){
            if(pos != strs[i].find(c)){
                c = c.substr(0, c.length()-1);
                i = 0;
            }
        }

        return c;
    }
};

int main(int argc, char* argv[]){
    Solution s;

    vector<string> strs = {"abca","aba","aaab"};

    cout << s.longestCommonPrefix(strs) << endl;
    
    // string a = "acc";
    // cout << a.find("a") << endl;
    // cout << a.find("c") << endl;
    // cout << a.substr(0,a.length()-1) << endl;
    // cout << a.substr(0,0) << endl;
    return 0;
}