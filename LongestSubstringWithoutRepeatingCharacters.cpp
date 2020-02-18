#include <iostream>   // std::cout, std::endl;
#include <algorithm>  // std::sort, std::unique
#include <vector>     // std::vector
#include <stdio.h>    // printf
#include <map>
using namespace std;


std::vector<int> find_all(const std::string str, const std::string subStr) {
    std::vector<int> result;
 
    int subStrSize = subStr.size();
    int pos = str.find(subStr);
 
    while (pos != std::string::npos) {
        result.push_back(pos);
        pos = str.find(subStr, pos + subStrSize);
    }
 
    return result;
}

string filterString(string origin){
    
    vector<char> vec_fillter;
    string filterString;
    for(auto e: origin){
        vec_fillter.push_back(e);
    }
    sort(vec_fillter.begin(), vec_fillter.end());
    vec_fillter.erase(unique(vec_fillter.begin(), vec_fillter.end()), vec_fillter.end());
    for(auto e: vec_fillter){
        filterString += e;
    }

    return filterString;
}

class Solution {
public:

    int lengthOfLongestSubstring(string s) {

        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        vector<char> vec_fillter;
        string fs= filterString(s);

        cout << fs << "[" << fs.length() << "]" << endl;

        if(fs.length() == 1){
            return 1;
        }
        
        if(fs.length() >= 50 && s.length()%fs.length() == 0)
            return fs.length();

        string result = "";
        vector<int> saveCounter;
        int counter = 1;

        for(int h = 0; h < s.length(); h++){
            for(int i = h; i < s.length(); i++){
                result += s[i];
                //sort(result.begin(), result.end());
                cout << result << endl;   
                map<char, bool> dic;
                counter = 0;
                for(int j = 0; j < result.length(); j++){
                    if(dic[result[j]]){
                        result = s[i];
                        break;
                    }

                    if(dic[result[j]] == false){
                        dic[result[j]] = true;
                        counter += 1;
                    }

                    if(j == 0) continue;

                    if(result[j-1] == result[j]){
                        counter -= 1;
                    }
                }
                saveCounter.push_back(counter);
            }
            result = "";
        }

         if(saveCounter.size() == 0)
                    saveCounter.push_back(0);        

        return  *max_element(begin(saveCounter), end(saveCounter));

    }
};


int main(int argc, char * argv[]){

    Solution ret;
    //cout << ret.lengthOfLongestSubstring("cwsxtljaxz") << endl;
    // cout << ret.lengthOfLongestSubstring("pwwkew") << endl;
    // cout << ret.lengthOfLongestSubstring("bbbbbb") << endl;
    // cout << ret.lengthOfLongestSubstring("abcabcbb") << endl;
    //cout << ret.lengthOfLongestSubstring("abba") << endl;
    // cout << ret.lengthOfLongestSubstring("aab") << endl;
    //cout << ret.lengthOfLongestSubstring("abcb") << endl;
    // cout << ret.lengthOfLongestSubstring("dvdf") << endl;
    //cout << ret.lengthOfLongestSubstring("jlygy") << endl;
    // cout << ret.lengthOfLongestSubstring("ckilbkd") << endl;
    //cout << ret.lengthOfLongestSubstring("asjrgapa") << endl;
    
    //cout << ret.lengthOfLongestSubstring("hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") << endl;
    //cout << ret.lengthOfLongestSubstring("pzrljeewronkdblgszkllozdbndj");


    
    return 0;
}



// "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789
// hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789
// hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789
// hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789
// hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789
// hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

//pzrlje
//ewronkdblgszkl
//lozdbndj
