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

string intToString(int number, bool &checker){
    string str = to_string(number);
    if(str.find("-") != string::npos){
        checker = true;
        str.erase(str.find("-"), 1);
        //cout << number << ", [" <<checker << "], " << str <<endl;
    }
    return str;
}

class Solution {
public:
    int divide(int dividend, int divisor) {

        if(divisor == 0){
            return 0;
        }

        if(abs(dividend) < abs(divisor)){
            return 0;
        }
        
        int first[] = { dividend}; 
  
        int second[] = { divisor}; 
  
        int results[1]; 

        transform(first, first + 1, second, results, divides<int>());        

        return results[0];
    }
};

int main(int argc, char* argv[]){

    Solution s;
    int dividend = -10;
    int divisor = 3;

    cout << "dividend -> " << dividend << endl;
    cout << "divisor  -> " << divisor << endl;

    cout << s.divide(dividend, divisor) << endl;

    return 0;

}
