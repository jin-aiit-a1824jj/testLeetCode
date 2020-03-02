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
    int search(vector<int>& nums, int target) {

        auto result = find(begin(nums), end(nums), target);
        if (result == end(nums)){
            return -1;
        }

        return distance(nums.begin(), result);
    }
};

int main(int argc, char* argv[]){

    Solution s;
    
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    cout << s.search(nums, target) << endl;


    return 0;

}