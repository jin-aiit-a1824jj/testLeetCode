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
    int romanToInt(string s) {
        
        int result = 0;

        for(int i = 0; i< s.length(); i++){
            if(i+1 < s.length()){
                string temp = s.substr(i, 2);
                if(temp == "CM"){
                    result += 900;
                    i += 1;
                    continue;
                }

                if(temp == "CD"){
                    result += 400;
                    i += 1;
                    continue;
                }

                if(temp == "XC"){
                    result += 90;
                    i += 1;
                    continue;
                }

                if(temp == "XL"){
                    result += 40;
                    i += 1;
                    continue;
                }

                if(temp == "IX"){
                    result += 9;
                    i += 1;
                    continue;
                }

                if(temp == "IV"){
                    result += 4;
                    i += 1;
                    continue;
                }
            }
            
            
            
            if(s[i] == 'M'){
                result += 1000;
                continue;
            }

            if(s[i] == 'D'){
                result += 500;
                continue;
            }

            if(s[i] == 'C'){
                result += 100;
                continue;
            }

            if(s[i] == 'L'){
                result += 50;
                continue;
            }

            if(s[i] == 'X'){
                result += 10;
                continue;
            }

            if(s[i] == 'V'){
                result += 5;
                continue;
            }

            if(s[i] == 'I'){
                result += 1;
                continue;
            }
        }

        return result;
    }
};


int main(int argc, char* argv[]){
    Solution s;
    cout << s.romanToInt("MCMXCIV") << endl;
    return 0;
}