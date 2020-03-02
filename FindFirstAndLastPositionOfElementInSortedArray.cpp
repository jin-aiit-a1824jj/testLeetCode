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
#include <iterator>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        auto result = find(begin(nums), end(nums), target);
        if(result == end(nums)){
            return {-1, -1};
        }

        auto reverseResult = find(nums.rbegin(), nums.rend(), target);
        if(reverseResult ==  nums.rend()){
            return {-1, -1};
        }

        return {
            (int)distance(nums.begin(), result),
            (int)nums.size() - 1 - (int)distance(nums.rbegin(), reverseResult)
        };
    }
};

int main(int argc, char* argv[]){

    Solution s;
    
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;

    for(auto e : s.searchRange(nums, target)){
        cout << e << ", ";
    }

    

    //auto result = find(begin(nums), end(nums), target);
    //cout << distance(nums.begin(), result) << endl;

    return 0;

}