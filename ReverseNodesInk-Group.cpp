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

int GetListNodeSize(ListNode* node){
    int counter = 0;
    while(true){
        if(node == NULL)
            break;      
        counter++;
        if(node->next == NULL)
            break;
        node = node->next;
    }
    return counter;
}

void SetValueListNode(vector<int>& vec, ListNode* node){
    int number = 0;
    while(true){
        if(node == NULL)
            return;
        node->val = vec[number++];
        if(node->next == NULL)
            return;
        node = node->next;
    }
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head == NULL) return head;
        if(k < 1) return head;

        int size = GetListNodeSize(head);
        if(size < k) return head;
        //cout << size << "/" << k << " = " << size/k << endl; 
        
        ListNode* node = head;
        vector<int> vec;
        while(true){
            vec.push_back(node->val);
            if(node->next == NULL)
                break;
            node = node->next;
        }

        for(int i = 0; i< vec.size(); i+= k){
            if(i%k != 0) continue;
            if(i+k >= vec.size()) continue;
            cout << i << "%" << k << " = " << i%k << "  " << vec.size() << ", "<<  i + k <<endl;
            auto start = vec.begin() + i;
            auto end = vec.begin() + i + k;
            reverse(start, end);
        }

        SetValueListNode(vec, head);

        return head;
    }
};

int main(int argc, char* argv[]){
    
    Solution s;

    auto r0 = new ListNode(1);
    auto r1 = new ListNode(7);
    auto r2 = new ListNode(3);
    auto r3 = new ListNode(2);
    auto r4 = new ListNode(7);
    auto r5 = new ListNode(0);
    auto r6 = new ListNode(1);
    auto r7 = new ListNode(0);
    auto r8 = new ListNode(0);

    r0->next = r1;
    r1->next = r2;
    r2->next = r3;
    r3->next = r4;
    r4->next = r5;
    r5->next = r6;
    r6->next = r7;
    r7->next = r8;

    int k = 4;

    auto ret = s.reverseKGroup(r0, k);
    
    while(true){

        if(ret == NULL)
            break;
        cout << ret->val << "-> ";

        if(ret->next == NULL)
            break;
        ret = ret->next;
    }


    delete r0;
    delete r1;
    delete r2;
    delete r3;
    delete r4;
    delete r5;
    delete r6;
    delete r7;
    delete r8;

    return 0;
}

