#include <iostream>   // std::cout, std::endl;
#include <algorithm>  // std::sort, std::unique
#include <vector>     // std::vector
#include <stdio.h>    // printf
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> r;

        for(int i = 0; i < nums.size(); i++){
            for(int j = 1; j < nums.size(); j++){
                auto calc = nums.at(i) + nums.at(j);

                if(i == j)
                    continue;

                if(calc == target){
                    printf("i[%d] j[%d]\n", i, j);
                    r.push_back(i);
                    r.push_back(j);
                    break;
                }
            }
        }
        
        sort(r.begin(), r.end());
        r.erase(unique(r.begin(), r.end()), r.end());

        return r;
    }
};

int main(){
    
    auto a = new Solution();
   
    //vector<int> v = {2, 7, 11, 15};
    vector<int> v = {-1, -2, -3, -4, -5};
    int target = -8;

    auto result = a->twoSum(v, target);
    for(int i = 0; i < result.size(); i++)
        cout << result.at(i) << endl;
    

    delete a;
    return 0;
}