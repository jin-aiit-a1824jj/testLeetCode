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
    int removeElement(vector<int>& nums, int val) {
         for (auto it = nums.begin(); it != nums.end();) {
            if (*it == val) {
                it = nums.erase(it);
            } else {
                ++it;
            }
        }
        return nums.size();
    }
};

int main(int argc, char* argv[]){
    
    Solution s;
    vector<int> nums = {3,2,2,3};
    int val = 3;
    cout << s.removeElement(nums, val) << endl;
    return 0;

}