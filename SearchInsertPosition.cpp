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
    int searchInsert(vector<int>& nums, int target) {
        auto result = find_if(nums.begin(), nums.end(), [target](int &n){
            return target <= n ;
        });

        return (int)distance(nums.begin(), result);
    }
};

int main(int argc, char* argv[]){

    Solution s;
    
    vector<int> nums = {1,3,5,6};
    int target = 5;

    cout << s.searchInsert(nums, target) << endl;

    

    //auto result = find(begin(nums), end(nums), target);
    //cout << distance(nums.begin(), result) << endl;

    return 0;

}