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
#include <numeric>// std::accumulate
#include <math.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        for(int i = 0; i < 1000; i++){
            auto result  = find(nums.begin(), nums.end(), i);
            if(result == nums.end()){
                return i;
            }
        }
        return -1;
        // auto find = min_element(nums.begin(), nums.end());
        // cout << *find << endl;
        // cout << *max_element(nums.begin(), nums.end()) << endl;
        // return distance(nums.begin(), find);   
    }
};

int main(int argc, char* argv[]){

    Solution s;
    //vector<int> nums = {3,4,-1,1};
    vector<int> nums =
    {99,94,96,11,92,5,91,89,57,85,66,63,84,81,79,61,74,78,77,30,64,13,58,18,70,69,51,12,32,34,9,43,39,8,1,38,49,27,21,45,47,44,53,52,48,19,50,59,3,40,31,82,23,56,37,41,16,28,22,33,65,42,54,20,29,25,10,26,4,60,67,83,62,71,24,35,72,55,75,0,2,46,15,80,6,36,14,73,76,86,88,7,17,87,68,90,95,93,97,98};

    cout << s.firstMissingPositive(nums) << endl;



    return 0;

}