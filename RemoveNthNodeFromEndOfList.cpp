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

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

int getSize(ListNode* head){
    int size = 1;
    auto ret = head->next;
    
     while(true){
        if(ret == NULL)
            break;
        else
            size++;
        ret = ret->next;
    }
    cout << "NodeSize->" << size << endl;
    return size;
}

ListNode* getPointer(ListNode* head, int target){
    int size = 0;
    auto ret = head;
    if(target == 0)
     return ret;
    
    while(true){
        if(ret == NULL)
            break;
        else
            size++;

        ret = ret->next;

        if(size == target)    
            break;
    }

    return ret;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == NULL)
            return NULL;

        int size = getSize(head);


        if(size == 1 && n == 1){
            return NULL;
        }
        
        
        auto targetBefore = getPointer(head, size - n - 1);
        auto targetAfrer = getPointer(head, size - n + 1);

        if(targetBefore != NULL && targetAfrer != NULL){
            targetBefore->next = targetAfrer;
        }else if(targetBefore != NULL && targetAfrer == NULL){
            targetBefore->next = NULL;
        }else if(targetBefore == NULL && targetAfrer != NULL){
            return targetAfrer;
        }
        
        return head;
    }
};

int main(int argc, char* argv[]){
    
    Solution s;


    // auto r5 = new ListNode(5);
    // auto r4 = new ListNode(4);
    // auto r3 = new ListNode(3);
    //auto r2 = new ListNode(2);
    auto r1 = new ListNode(1);

    //r1->next = r2;
    // r2->next = r3;
    // r3->next = r4;
    // r4->next = r5;

    auto ret = s.removeNthFromEnd(r1, 1);

    while(true){
        if(ret == NULL)
            break;
        else
            cout << ret->val << "-> ";
        
        ret = ret->next;
    }

    // delete r5;
    // delete r4;
    // delete r3;
    //delete r2;
    delete r1;

    return 0;
}