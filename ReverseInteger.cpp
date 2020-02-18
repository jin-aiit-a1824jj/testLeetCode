#include <iostream>   // std::cout, std::endl;
#include <algorithm>  // std::sort, std::unique
#include <vector>     // std::vector
#include <stdio.h>    // printf
#include <map>
#include <queue>
#include <string.h> //strcmp、strncmp関数を使うために必要
#include <stdexcept>
#include <climits>
using namespace std;


class Solution {
public:
    int reverse(int a) {

        if(INT_MIN == a){
            return 0;
        }

        bool isMinuse = false;
        if(a < 0){ 
            isMinuse = true;
            a = a * -1;
        }
        cout << a << endl;
        string str = to_string(a);
        std::reverse(str.begin(), str.end());
        if(isMinuse){
            str = "-" + str;
        }
        cout << (isMinuse ? "-" + str : str) << endl;

        int result = 0;

        try{
            result = stoi(str);
        }catch (const std::out_of_range& e){
            cout << "[" << str << "]: " << "out of range" << endl;
            result = 0;
        }

        return result;
    }
};


int main(int argc, char* argv[]){
    Solution s;
    int a = -2147483648;
    cout << s.reverse(a) << endl;

    return 0;
}
