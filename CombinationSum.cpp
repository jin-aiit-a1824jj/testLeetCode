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

//https://bettamodoki.hatenadiary.jp/entry/20151104/1446603409 C++でcombination
/*
template <typename Tlist, typename Tfunc>
void __combination(
    Tlist const& list, typename Tlist::size_type const n, Tfunc const& func,
    Tlist& tmp, typename Tlist::size_type const i, typename Tlist::size_type const j)
{
    if (i == n)
    {
        func(tmp);
        return;
    }

    for (typename Tlist::size_type k = j; k != list.size() + (1 + i- n); ++k)
    {
        tmp[i] = list[k];
        __combination(list, n, func, tmp, i + 1, k + 1);
    }
}

template <typename Tlist, typename Tfunc>
void combination(
    Tlist const& list, typename Tlist::size_type const n, Tfunc const& func)
{
    Tlist tmp(n);
    __combination(list, n, func, tmp, 0, 0);
}

for(int c = 0; c < candidates.size(); c++){
            combination( candidates, c, [&result, &target](vector<int> const& a) {
                vector<int> temp;
                for (auto i(a.begin()) ; i != a.end() ; ++i){
                    temp.push_back(*i);
                }
                int sum = accumulate(a.begin(), a.end(), 0);
                if(sum == target)
                    result.push_back(temp);
            });
}

*/

//https://m.blog.naver.com/PostView.nhn?blogId=ndb796&logNo=220912159147&proxyReferer=https%3A%2F%2Fwww.google.com%2F
//https://stackoverflow.com/questions/12631514/how-can-i-print-out-the-contents-of-stdstack-and-return-its-size
//https://stackoverflow.com/questions/4346010/copy-stdstack-into-an-stdvector

/*
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;

        stack<int> stack;
        stack.push(target);
        
        while(true){

            auto end = &stack.top() + 1;
            auto begin = end - stack.size();
            vector<int> vec(begin, end);

            sort(vec.begin(), vec.end());
            vec.erase(unique(vec.begin(), vec.end()), vec.end());

            vector<bool> checker;
            for(auto e: vec){
                for(auto c: candidates){
                    if(e == c){
                        checker.push_back(true);
                    }
                }
            }

            if(checker.size() == vec.size()){
                vector<int> save(begin, end);
                result.push_back(save);
            }         

            int temp = stack.top();
            stack.pop();
            if(temp != 1){
                stack.push(temp - 1);
                stack.push(1);
            }else{
                int sum = 2;
                for( ; !stack.empty() && stack.top() == 1; stack.pop()){
                    sum++;
                }

                if(stack.empty())
                    break;

                int pivot = stack.top() - 1;
                stack.pop();
                stack.push(pivot);

                while(sum > pivot){
                    stack.push(pivot);
                    sum -= pivot;
                }
                stack.push(sum);
            }
        }


        return result;
    }
};
*/

//https://leetcode.com/problems/combination-sum/discuss/16496/Accepted-16ms-c%2B%2B-solution-use-backtracking-easy-understand.

void combinationSum2(vector<int> &candidates, int target, vector<std::vector<int> > &res, vector<int> &combination, int begin) {
    if (!target) {
        for(auto e : combination){
            cout << e << ", ";
        }
        cout << endl;
        res.push_back(combination);
        return;
    }
        
    for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i){
        if (i == begin || candidates[i] != candidates[i - 1]) {
            combination.push_back(candidates[i]);
            combinationSum2(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> combination;
        combinationSum2(candidates, target, res, combination, 0);
        return res;
    }
};

int main(int argc, char* argv[]){

    Solution s;

    //vector<int> candidates = {48,22,49,24,26,47,33,40,37,39,31,46,36,43,45,34,28,20,29,25,41,32,23};
    // vector<int> candidates =  {2,3,5};
    vector<int> candidates = {2,3,6,7};
    int target = 7;//69;//8;//7;
    
    auto ret = s.combinationSum(candidates, target);

    for(auto row : ret){
        for(auto e : row){
            cout << e << ", "; 
        }
        cout << endl;
    }



    return 0;

}