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


void combinationSum3(vector<int> &candidates, int target, vector<std::vector<int> > &res, vector<int> &combination, int begin) {
    if (!target) {
        res.push_back(combination);
        return;
    }
        
    for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i){
        if (i == begin || candidates[i] != candidates[i - 1]) {
            combination.push_back(candidates[i]);
            combinationSum3(candidates, target - candidates[i], res, combination, i+1);
            combination.pop_back();
        }
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> combination;
        combinationSum3(candidates, target, res, combination, 0);
        return res;
    }
};