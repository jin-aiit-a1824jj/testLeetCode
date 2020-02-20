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

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for(int i = 0; i < nums.size(); i++){
            
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j = i + 1; j < nums.size(); j++){
                if(j > i + 1 && nums[j] == nums[j-1]) continue;

                int k = j + 1;
                int l = nums.size() - 1;

                while(k < l){
                    int calc = nums[i] + nums[j] + nums[k] + nums[l];
                    if(calc == target){
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while(k < l && nums[k] == nums[k-1]){
                            k++;
                        }
                        while(k < l && nums[l] == nums[l+1]){
                            l--;
                        }
                    } else if(calc > target){
                        l--;
                    } else{
                        k++;
                    }
                }
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]){
    
    Solution s;

    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    auto vecs = s.fourSum(nums, target);
    
    for(auto e: vecs){
        for(auto a : e){
            cout<< a << ", ";
        }
        cout << endl;
    }

    

    return 0;
}