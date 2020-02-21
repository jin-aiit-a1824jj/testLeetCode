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

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL && l2 == NULL)
            return NULL;
        
        if(l1 != NULL && l2 == NULL)
            return l1;
        
        if(l1 == NULL && l2 != NULL)
            return l2;


        vector<int> vec;

        auto ret = l1;
        while(true){
            if(ret == NULL)
                break;
            vec.push_back(ret->val);         
            if(ret->next)
                ret = ret->next;
            else
                break;
        }


        auto ret2 = l2;
        while(true){
            if(ret2 == NULL)
                break;
            vec.push_back(ret2->val);
            ret2 = ret2->next;
        }

        ret->next = l2;

        sort(vec.begin(), vec.end());

        if(vec.size() == 0){
            return NULL;
        }

        auto r = l1;
        for(auto e : vec){
            if(r == NULL)
                break;
            r->val = e;
            r = r->next;
        }
        
        return l1;
    }
};

int main(int argc, char* argv[]){

    auto a1 = new ListNode(1);
    auto a2 = new ListNode(2);
    auto a3 = new ListNode(4);

    a1->next = a2;
    a2->next = a3;

    auto b1 = new ListNode(1);
    auto b2 = new ListNode(3);
    auto b3 = new ListNode(4);

    b1->next = b2;
    b2->next = b3;


    Solution s;

    auto ret =  s.mergeTwoLists(a1, b1);

    while(true){
        if(ret == NULL)
            break;
        cout << ret->val <<"->";
        ret = ret->next;
    }

    return 0;
}