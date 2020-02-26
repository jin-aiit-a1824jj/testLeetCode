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

using namespace std;

map<string, int> dic;

void func(string str, vector<string> words, int counter, vector<string>& wordFilter,  const int originWordsLength, vector<string>& wordsOrigin){
    
    if(counter >= originWordsLength){
        cout << "[" << counter << "]  " << str<<"    " << "push_back" << endl;
        wordFilter.push_back(str);
    }else{
        
        counter+=1;
        cout << "[" << counter << "]  " << str << endl;//<<"    " << "push_back" << endl; 
        
        for ( auto it = words.begin() ; it != words.end(); ) {
            int pos = str.find(*it);
            int length = (*it).length();
            if ( pos != string::npos && pos%length == 0) {
                cout << "[" << counter << "]  " << *it << "  <-remove...";
                it = words.erase(it);
                break;
            } else {
                ++it;
            }
        }
        
        //cout << endl;

        for(int i = 0; i < words.size(); i++){
            string temp = str + words[i];
            
            if(originWordsLength -1 == counter){
                map<string, int> dicChecker;
                for(auto e : words){
                    int pos = temp.find(e);
                    int length = e.length();
                    while(pos != string::npos && pos%length == 0){
                        dicChecker[e] += 1;
                        pos = temp.find(e, pos + e.size());
                    }

                    if(dicChecker[e] > dic[e]){
                        cout << temp << "  :  " << e << "  dicChecker[e]" << dicChecker[e] << "  , dic[e]" << dic[e] << "   " << endl;
                        return;
                    }
                }
            }

            func(temp, words, counter, wordFilter, originWordsLength, wordsOrigin);
        }
    }
}


class Solution {
public:
    //https://leetcode.com/problems/substring-with-concatenation-of-all-words/discuss/13658/Easy-Two-Map-Solution-(C%2B%2BJava)
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts;
        for (string word : words)
            counts[word]++;

        int n = s.length();
        int num = words.size();
        int len = words[0].length();

        vector<int> indexes;

        for (int i = 0; i < n - num * len + 1; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            
            for (; j < num; j++) {
                string word = s.substr(i + j * len, len);
                if (counts.find(word) != counts.end()) {
                    seen[word]++;
                    if (seen[word] > counts[word])
                        break;
                }
                else 
                    break;
            }

            if (j == num) 
                indexes.push_back(i);
        }
        return indexes;
    }


/*
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;

        if(s == "") return result;
        if(words.size() == 0) return result;
        dic.clear();
        string first = "";
        for(auto e: words){
            dic[e] += 1;
            first += e;
        }

        vector<string> wordFilter;
        wordFilter.push_back(first);

        func("", words, 0, wordFilter, words.size(), words);

        sort(wordFilter.begin(), wordFilter.end());
        wordFilter.erase(unique(wordFilter.begin(), wordFilter.end()), wordFilter.end());

        for(auto e: wordFilter){
            
            int pos = s.find(e);
            cout << e << " -- " << e.size() <<endl;
            while(pos != string::npos){
                
                result.push_back(pos);
                pos = s.find(e, pos + 1);
            }
        }
        return result;
    }*/

};

int main(int argc, char* argv[]){

    Solution s;

    //string str = "abaababbaba";
    //vector<string> words = {"ab","ba","ab","ba"};//{"foo","bar"};//{"word","good","best","word"};

    string str = "pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmyxgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoadfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjycttprkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwajrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhducesctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtraxrlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabejifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtqkscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyrdtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkpuuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjhzadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrowzljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrdhvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefgvimwbxcbzvaibspdjnrpqtyeilkcspknyylbwndvkffmzuriilxagyerjptbgeqgebiaqnvdubrtxibhvakcyotkfonmseszhczapxdlauexehhaireihxsplgdgmxfvaevrbadbwjbdrkfbbjjkgcztkcbwagtcnrtqryuqixtzhaakjlurnumzyovawrcjiwabuwretmdamfkxrgqgcdgbrdbnugzecbgyxxdqmisaqcyjkqrntxqmdrczxbebemcblftxplafnyoxqimkhcykwamvdsxjezkpgdpvopddptdfbprjustquhlazkjfluxrzopqdstulybnqvyknrchbphcarknnhhovweaqawdyxsqsqahkepluypwrzjegqtdoxfgzdkydeoxvrfhxusrujnmjzqrrlxglcmkiykldbiasnhrjbjekystzilrwkzhontwmehrfsrzfaqrbbxncphbzuuxeteshyrveamjsfiaharkcqxefghgceeixkdgkuboupxnwhnfigpkwnqdvzlydpidcljmflbccarbiegsmweklwngvygbqpescpeichmfidgsjmkvkofvkuehsmkkbocgejoiqcnafvuokelwuqsgkyoekaroptuvekfvmtxtqshcwsztkrzwrpabqrrhnlerxjojemcxel";
    vector<string> words = {"dhvf", "sind", "ffsl", "yekr", "zwzq", "kpeo", "cila", "tfty", "modg", "ztjg", "ybty", "heqg", "cpwo", "gdcj", "lnle", "sefg", "vimw", "bxcb"};


    auto vec = s.findSubstring(str, words);

    for(auto e: vec){
        cout << e <<", "; 
    }
    cout << endl;

    return 0;

}

