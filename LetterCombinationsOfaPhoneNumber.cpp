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

map<int, string> dic =
{
    make_pair(50,"abc"),//2
    make_pair(51,"def"),//3
    make_pair(52,"ghi"),//4
    make_pair(53,"jkl"),//5
    make_pair(54,"mno"),//6
    make_pair(55,"pqrs"),//7
    make_pair(56,"tuv"),//8
    make_pair(57,"wxyz")//9
};


void func(string str, string next_digits, vector<string> &result, int &counter){

    if(next_digits.size() == 0){
        //cout <<"[" << counter++ << "]" << str << endl;
        result[counter++] = str;
    }else{       
        for(int i = 0; i < dic[next_digits[0]].size(); i++ ){ 
            string chars = dic[next_digits[0]].substr(i, 1);
            //cout <<"[" << counter << "]" << chars << endl;
            func(str + chars,  next_digits.substr(1), result, counter);
        }
    
    }

}

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        int resultVectorElementNumber = 0;
        
        for(auto e : digits){            
        
            if(e == '1' || e == '0' || e == '*' || e == '#'){
                continue;
            }

            bool adjustNumber = false;

            if(e == '7' || e == '9'){
                adjustNumber = true;
            }
            
            if(resultVectorElementNumber == 0){
                if(adjustNumber)
                    resultVectorElementNumber = 4;
                else
                    resultVectorElementNumber = 3;
            }else{
                if(adjustNumber)
                    resultVectorElementNumber *= 4;
                else
                    resultVectorElementNumber *= 3;
            }
        }
        
        cout << "resultVectorElementNumber->  " << resultVectorElementNumber << endl;
        vector<string> result(resultVectorElementNumber);
        int counter = 0;

        func("",digits, result, counter);
      
        return result;
    }
};


int main(int argc, char* argv[]){
    
    Solution s;
    auto vec = s.letterCombinations("2345");
    
    for(auto e: vec){
        cout<< e << ", ";
    }

    

    return 0;
}