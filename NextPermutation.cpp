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

class Solution {
public:
    //https://qiita.com/siser/items/a91022071b24952d27d9
    //https://cpprefjp.github.io/reference/algorithm/next_permutation.html
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

int main(int argc, char* argv[]){

    Solution s;

    vector<int> nums = {1, 2, 3};
    s.nextPermutation(nums);
    for(auto &e: nums ){
        cout << e << ", ";
    }

    return 0;

}