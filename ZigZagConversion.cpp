#include <iostream>   // std::cout, std::endl;
#include <algorithm>  // std::sort, std::unique
#include <vector>     // std::vector
#include <stdio.h>    // printf
#include <map>
#include <queue>
#include <string.h> //strcmp、strncmp関数を使うために必要
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        
        if(s.length() == 0) return "";
        if(numRows < 2) return s;

        map<int, vector<int>> dic;
        int arr[numRows][s.length()];
        //std::fill(&arr[0][0], &arr[numRows][s.length()], 0);



        for(int i = 0; i < numRows; i++){
          for(int j = 0; j < s.length() ; j++){
                arr[i][j] = 0;
                // char c = arr[i][j];
                // cout << c << "[" << i << "]" << "[" << j << "]->" << (int)c << endl;
            }
        }

        int yoko = 0;
        int tate = 0;
        bool yokoReverseFlag = false;

        for(int i = 0; i < s.length(); i++){
            char c = s.at(i);
            cout << c << "[" << yoko << "]" << "[" << tate << "]->" << (int)c << endl;
            arr[yoko][tate] = (int)c;
            dic[i] = {yoko, tate};

            if(!yokoReverseFlag){
                yoko += 1;
                if(yoko == numRows -1){
                    yokoReverseFlag = true;
                }
            }else{
                yoko -= 1;
                if(yoko == 0){
                    yokoReverseFlag = false;
                }
                tate += 1;
            }
        }
        
        cout << endl;
        cout << endl;
        cout << endl;

        string result;

        for(int i = 0; i < numRows; i++){
          for(int j = 0; j < s.length() ; j++){
                char c = arr[i][j];
                cout << c << "[" << i << "]" << "[" << j << "]->" << (int)c << endl;
            }
        }
        
        return result;
    }
};

int main(){

    Solution r;


    string a = "Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.";
    cout << r.convert(a, 2) << endl;    

    return 0;
}
