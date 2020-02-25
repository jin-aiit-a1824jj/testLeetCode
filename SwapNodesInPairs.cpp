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
    ListNode* swapPairs(ListNode* head) {

        ListNode* node = head;
        while(true){
            if(node == NULL)
                break;      
            if(node->next == NULL)
                break;

            swap(node->val, node->next->val);

            node = node->next->next;
        }


        return head;
    }
};

int main(int argc, char* argv[]){
    
    Solution s;

    auto r0 = new ListNode(1);
    auto r1 = new ListNode(2);
    auto r2 = new ListNode(3);
    auto r3 = new ListNode(4);

    r0->next = r1;
    r1->next = r2;
    r2->next = r3;

    auto ret = s.swapPairs(r0);
    
    while(true){

        if(ret == NULL)
            break;
        cout << ret->val << "-> ";

        if(ret->next == NULL)
            break;
        ret = ret->next;
    }

    return 0;
}
