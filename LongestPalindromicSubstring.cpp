#include <iostream>   // std::cout, std::endl;
#include <algorithm>  // std::sort, std::unique
#include <vector>     // std::vector
#include <stdio.h>    // printf
#include <map>
#include <queue>
#include <string.h> //strcmp、strncmp関数を使うために必要
using namespace std;

int expandAroundCenter(string s, int left, int right){
    
    int L = left;
    int R = right;

    while(L >= 0 && R < s.length() && s[L] == s[R]){
        L--;
        R++;
    }
    return R - L - 1;
}

string func(string s){

    int start = 0;
    int end = 0;
        
    for(int i = 0; i < s.length(); i++){
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i+1);
        int len = max(len1, len2);
        
        //cout << len1 <<", "<< len2 <<"  ";
        //cout << len << "=" << end << "-" << start << endl;
        
        if(len > end - start){
            start = i - ( len - 1) / 2;
            end = i + len / 2;
        }
    }

    return s.substr(start, end + 1);
}

class Solution {
public:

    string longestPalindrome(string s) {
        if(s.length() == 0) return "";
        if(s.length() == 1) return s;

        string response = func(s);
        string reverStr = string(response);
        reverse(reverStr.begin(), reverStr.end());
        
        if(response == reverStr)
            return response;

        return func(response);
    }

/*
    string longestPalindrome(string s) {

        if(s == "")
            return "";

        string reverStr = string(s);
        reverse(reverStr.begin(), reverStr.end());

        cout << s << endl;
        cout << reverStr << endl;

        int dp[1000+1][1000+1];
        map<int, string> dic;


        for (int i=0; i < s.length() ; ++i) {
            for (int j=0; j < reverStr.length() ; ++j) {
                if (s[i] == reverStr[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                }else {
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }

        //cout << s.length() << endl;
        cout << dp[s.length()][reverStr.length()] << endl;


        int flag = dp[s.length()][reverStr.length()];
        string result;
        for(int i = 0; i < s.length(); i++){
            for(int j = 1; j <= flag; j++){
                result = s.substr(i, j);
                string temp = s.substr(i, j);
                reverse(temp.begin(), temp.end());
                if(temp == result){
                    //cout << temp << ":" << result << endl;
                    dic[temp.length()] = temp;
                }
                    
            }
            
        }

        return dic[dic.rbegin()->first];
    }
    */
};


int main(){

    Solution r;
 
    //string s = "abcdbbfcba";
    string s = "lcnvoknqgejxbfhijmxglisfzjwbtvhodwummdqeggzfczmetrdnoetmcydwddmtubcqmdjwnpzdqcdhplxtezctvgnpobnnscrmeqkwgiedhzsvskrxwfyklynkplbgefjbyhlgmkkfpwngdkvwmbdskvagkcfsidrdgwgmnqjtdbtltzwxaokrvbxqqqhljszmefsyewwggylpugmdmemvcnlugipqdjnriythsanfdxpvbatsnatmlusspqizgknabhnqayeuzflkuysqyhfxojhfponsndytvjpbzlbfzjhmwoxcbwvhnvnzwmkhjxvuszgtqhctbqsxnasnhrusodeqmzrlcsrafghbqjpyklaaqximcjmpsxpzbyxqvpexytrhwhmrkuybtvqhwxdqhsnbecpfiudaqpzsvfaywvkhargputojdxonvlprzwvrjlmvqmrlftzbytqdusgeupuofhgonqoyffhmartpcbgybshllnjaapaixdbbljvjomdrrgfeqhwffcknmcqbhvulwiwmsxntropqzefwboozphjectnudtvzzlcmeruszqxvjgikcpfclnrayokxsqxpicfkvaerljmxchwcmxhtbwitsexfqowsflgzzeynuzhtzdaixhjtnielbablmckqzcccalpuyahwowqpcskjencokprybrpmpdnswslpunohafvminfolekdleusuaeiatdqsoatputmymqvxjqpikumgmxaxidlrlfmrhpkzmnxjtvdnopcgsiedvtfkltvplfcfflmwyqffktsmpezbxlnjegdlrcubwqvhxdammpkwkycrqtegepyxtohspeasrdtinjhbesilsvffnzznltsspjwuogdyzvanalohmzrywdwqqcukjceothydlgtocukc";
    //string s = "babad";
    // cout << s << endl;
    // for(auto e: s) cout << (int)e << ",";
    // cout << endl;
    cout << r.longestPalindrome(s) << endl;

    return 0;
}