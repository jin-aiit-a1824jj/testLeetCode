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
    int maxArea(vector<int>& height) {

         int result = 0;

        // for(int x = 0; x < height.size(); x++){
        //     for(int y = 0; y < height.size(); y++){    
        //         int w = y - x;
        //         int h = min(height.at(x), height.at(y));
        //         int calc = w * h;
        //         result = max(calc, result);
        //     }
        // }


        int left = 0;
        int right = height.size() -1;
        while(left < right){
            int w = right - left;
            int h = min(height.at(left), height.at(right));
            int calc = w * h;
            result = max(calc, result);
            if(height.at(left)< height.at(right))
                left++;
            else
                right--;
            cout << calc << endl;
        }

        return result;
    }
};


int main(int argc, char* argv[]){
    Solution s;
    vector<int> height;
    for(int i = 0; i < 15001; i++){
        height.push_back(15000 - i);
    }
    cout << s.maxArea(height) << endl;
    return 0;
}