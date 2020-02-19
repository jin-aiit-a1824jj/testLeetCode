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

    int threeSumClosest(vector<int>& nums, int target) {

        if(nums.size() == 3){
            return nums[0] + nums[1] + nums[2];
        }

        sort(nums.begin(), nums.end());
        
        int result = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < nums.size() ; i++){
            
            if(i > 0 && nums[i] == nums[i -1]) continue;   

            int lo = i+1;
            int hi = nums.size() - 1;

            while(lo < hi){
                
                
                int a = nums[i];
                int b = nums[lo];
                int c = nums[hi];
                int calc = a + b + c;

                cout << "[" << a<< "] + [" << b << "] + [" << c << "] => " << calc << endl;

                int tempCompare = abs(target - calc);
                if( tempCompare == 0){
                    cout << "tempCompare == 0" << endl;
                    return calc;
                }

                int savedTempCompare = abs(target - result);
                //cout << ",              tempCompare[" << tempCompare <<",  savedTempCompare[" << savedTempCompare << endl;
                if (savedTempCompare > tempCompare ){
                    cout << result << "]result > tempCompare[" << tempCompare << endl;
                    result = calc;
                }

                
                if(calc > target){
                    hi--;
                }else{
                    lo++;
                }


            }

        }

        return result;
    }
};

int main(int argc, char* argv[]){
    Solution s;
    //vector<int> nums = {-1, 2, 1, -4};
    //int target = 1;

    //vector<int> nums = {87,6,-100,-19,10,-8,-58,56,14,-1,-42,-45,-17,10,20,-4,13,-17,0,11,-44,65,74,-48,30,-91,13,-53,76,-69,-19,-69,16,78,-56,27,41,67,-79,-2,30,-13,-60,39,95,64,-12,45,-52,45,-44,73,97,100,-19,-16,-26,58,-61,53,70,1,-83,11,-35,-7,61,30,17,98,29,52,75,-73,-73,-23,-75,91,3,-57,91,50,42,74,-7,62,17,-91,55,94,-21,-36,73,19,-61,-82,73,1,-10,-40,11,54,-81,20,40,-29,96,89,57,10,-16,-34,-56,69,76,49,76,82,80,58,-47,12,17,77,-75,-24,11,-45,60,65,55,-89,49,-19,4};
    //int target = -275;

    //vector<int> nums = {1,1,-1,-1,3};
    //int target =3;


    // vector<int> nums = {1,1,1,0};
    // int target = -100;

    //vector<int> nums = {0,2,1,-3};
    //int target = 1;

    // vector<int> nums = {0,2,1,-3};
    // int target = 1;

    //vector<int> nums = {-55, -24, -18, -11, -7, -3, 4, 5, 6, 9, 11, 23, 33};
    //int target = 0;

    // for(auto a : nums){
    //     for(auto b: nums){
    //         for(auto c: nums){
    //             if(a+b+c == 0 && a != b && b != c && c != a){
    //                 cout << "a[" << a <<"], b["<< b <<"], c["<< c <<"]"<< endl;
    //             }
    //         }
    //     }
    // }

    //vector<int> nums = {1,-1,3,-3};
    //int target =1;

    vector<int> nums = {1,2,4,8,16,32,64,128};
    int target =82;

    cout << s.threeSumClosest(nums, target) << endl;



    return 0;
}