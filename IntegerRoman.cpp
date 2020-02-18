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
using namespace std;

map <int, string> dic { 
    {1, "I"},
    {5, "V"},
    {10, "X"},
    {50, "L"},
    {100, "C"},
    {500, "D"},
    {1000, "M"}             
};


class Solution {
public:
    string intToRoman(int num) {
        
        string result = "";
        string str = to_string(num);
        int n = num;
        while(true){
            int div = (n > 1000 ? 1000 : n > 100 ?  100 : n > 10 ? 10 : 1);
            int v_calc = n/div;
            int calc = n%div;
            cout << v_calc << "/" << calc << "<- "<< div << endl;
            
            if(div == 1){
                if(0 < v_calc && v_calc < 4){
                    for(int i = 0; i < v_calc; i++){
                        result += dic[1];
                    }
                }

                if(v_calc == 4){
                    result += dic[1];
                    result += dic[5];
                }

                if(4 < v_calc && v_calc < 9){
                    result += dic[5];
                    for(int i = 0; i < v_calc - 5; i++){
                        result += dic[1];
                    }
                }

                if(v_calc == 9){
                    result += dic[1];
                    result += dic[10];
                }

                if(v_calc == 10){
                    result += dic[10];
                }
            }    

            if(div == 10){
                if(0 < v_calc && v_calc < 4){
                    for(int i = 0; i < v_calc; i++){
                        result += dic[10];
                    }
                }

                if(v_calc == 4){
                    result += dic[10];
                    result += dic[50];
                }

                if(4 < v_calc && v_calc < 9){
                    result += dic[50];
                    for(int i = 0; i < v_calc - 5; i++){
                        result += dic[10];
                    }
                }

                if(v_calc == 9){
                    result += dic[10];
                    result += dic[100];
                }

                if(v_calc == 10){
                    result += dic[100];
                }
            }

            if(div == 100){
                if(0 < v_calc && v_calc < 4){
                    for(int i = 0; i < v_calc; i++){
                        result += dic[100];
                    }
                }

                if(v_calc == 4){
                    result += dic[100];
                    result += dic[500];
                }

                if(4 < v_calc && v_calc < 9){
                    result += dic[500];
                    for(int i = 0; i < v_calc - 5; i++){
                        result += dic[100];
                    }
                }

                if(v_calc == 9){
                    result += dic[100];
                    result += dic[1000];
                }

                if(v_calc == 10){
                    result += dic[1000];
                }
            }

            if(div == 1000){
                if(0 < v_calc && v_calc < 4){
                    for(int i = 0; i < v_calc; i++){
                        result += dic[1000];
                    }
                }
            }

            
            if(calc <= 0){
                break;
            }else{
                n = calc;
            }
        }



        return result;
    }
};


int main(int argc, char* argv[]){
    Solution s;
    for(int i = 10; i < 21; i++)
        cout << s.intToRoman(i) << endl;
    return 0;
}