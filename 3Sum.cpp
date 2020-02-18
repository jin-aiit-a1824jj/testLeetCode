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

using namespace std;

namespace std {
    template <>
    struct hash<std::vector<int>> {
        size_t operator()(const vector<int>& v) const {
            // same thing
            return 0;
        }
    };
}


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

            vector <vector<int>> result;
            if(nums.size() == 0) return result;
            sort(nums.begin(), nums.end());

            for(int i = 0; i < nums.size()-1 ; i++){
                if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
                    int lo = i+1;
                    int hi = nums.size()-1;
                    int sum = 0 - nums[i];
                    while(lo < hi){
                        if(nums[lo] + nums[hi] == sum){
                            result.push_back({nums[i], nums[lo], nums[hi]});
                            while (lo < hi && nums[lo] == nums[lo+1]){
                                lo++;
                            }
                             
                            while (lo < hi && nums[hi] == nums[hi-1]){
                                hi--;
                            }
                             
                            lo++;
                            hi--;
                        }
                        else if(nums[lo] + nums[hi] < sum) lo++;
                        else hi--;
                    }
                }
            }

/*
            map<int, int> dic;
            for(auto e : nums){
                dic[e] += 1;
            }

            for(auto a: nums){
                for(auto b: nums){
                    for(auto c: nums){
                        if( a+b+c == 0){

                            map<int, int> checker;

                            checker[a] += 1;
                            checker[b] += 1;
                            checker[c] += 1;

                            if(dic[a] < checker[a]) continue;
                            if(dic[b] < checker[b]) continue;
                            if(dic[c] < checker[c]) continue;
                            
                            vector<int> temp = {a,b,c};
                            sort(temp.begin(), temp.end());
                            result.push_back(temp);
                            
                        }
                    }
                }
            }

            sort(result.begin(), result.end());
            result.erase(unique(result.begin(), result.end()), result.end());
*/
           return result;
    }
};

int main(int argc, char* argv[]){
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    //vector<int> nums =
    //{0,8,2,-9,-14,5,2,-5,-5,-9,-1,3,1,-8,0,-3,-12,2,11,9,13,-14,2,-15,4,10,9,7,14,-8,-2,-1,-15,-15,-2,8,-3,7,-12,8,6,2,-12,-8,1,-4,-3,5,13,-7,-1,11,-13,8,4,6,3,-2,-2,3,-2,3,9,-10,-4,-8,14,8,7,9,1,-2,-3,5,5,5,8,9,-5,6,-12,1,-5,12,-6,14,3,5,-11,8,-7,2,-12,9,8,-1,9,-1,-7,1,-7,1,14,-3,13,-4,-12,6,-9,-10,-10,-14,7,0,13,8,-9,1,-2,-5,-14};

    auto r = s.threeSum(nums);
    
    for(int i = 0; i < r.size(); i++){
        for(auto e: r[i]){
            cout << e << ",";
        }
        cout << endl;
    }

    return 0;
}