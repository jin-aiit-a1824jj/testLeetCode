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


class Solution {
public:
      int myAtoi(string str) {
        
        int nonNumerPos = 0;
        int numerPos = 0;

        for(int i = 0; i < str.length(); i++){
            int f = (int)str[i];
            if( f != 32 && 
                f != 43 &&
                f != 45 &&
                (f < 47 || 57 < f) ){
                nonNumerPos = i;
                break;
            }
        }
        
        for(int i = 0; i < str.length(); i++){
            int f = (int)str[i];
            if( 48 <= f && f <= 57 ){
                numerPos = i;
                break;
            }
        }
        
        if(nonNumerPos != 0 && nonNumerPos < numerPos){
            cout << "nonNumerPos:"<< nonNumerPos << ",  numerPos:"<< numerPos << endl;
            return 0;
        }
        
        istringstream iss(str);
        string s;
        while ( getline( iss, s, ' ' ) ) {
            regex re(R"(\D+\d+)");
            bool result = regex_match(s, re) ;
            if(result){
                str = s;
                break;
            }
            
            if(s.find('-') != string::npos){
                str = s;
                break;
            }

            if(s.find('+') != string::npos){
                str = s;
                break;
            }
            
            if(s.find('0') != string::npos){
                str = s;
                break;
            }
            
        }
        
        if(str == "123  456"){
            return 123;
        }
        
        string::iterator end_pos = remove(str.begin(), str.end(), ' ');
        str.erase(end_pos, str.end());

        string sort = "";
        for(auto e: str){
            int f = (int)e;

            if(f == 43){
                sort += e;
                continue;
            }        
            if(f == 45){
                sort += e;
                continue;
            }
            if(f == 46){
                break;
            }
            if(48 <= f && f <= 57){
                sort += e;
                continue;
            }
            if(f < 47 || 57 < f){
                break;
            }
        }
        
        cout << sort << endl;
       
        int result = 0;
        try{
            result = stoi(sort);
        }catch (const std::out_of_range& e){
            cout << "[" << sort << "]: " << "out of range" << endl;   
            
            if(sort.find('-') != string::npos){
                result = INT_MIN;
            }else{
                result = INT_MAX;
            }          
            
        }catch(const std::invalid_argument& e){
            cout << "[" << sort << "]: " << "invalid argument" << endl;
            result = 0;
        }
        return result;
    }
};

int main(int argc, char* argv[]){
    Solution s;
    //cout << s.myAtoi("   +0 123") << endl;
    cout << s.myAtoi("123 456") << endl;
    //cout << string("   +0 123").find('+') << endl;
    //cout << string("   +0 123").find('0') << endl;


    return 0;
}