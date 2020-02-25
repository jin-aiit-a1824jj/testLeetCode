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

int GetNodeSize(ListNode* node){
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

ListNode* GetLastNode(ListNode* node){
    while(true){
        cout << "GetLastNode" << endl;
        if(node == NULL)
            return NULL;      
        if(node->next == NULL)
            return node;
        node = node->next;
    }
    return NULL;
}

vector<int> GetValueVector(ListNode* node){ 
    vector<int> val;
    while(true){
        if(node == NULL)
            return val;
        val.push_back(node->val);
        if(node->next == NULL)
            return val;
        node = node->next;
    }
    return val;
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) 
            return NULL;

        ListNode* header = NULL;
        for(auto e : lists){
            if(e == NULL) continue;
            header = e;
            break;
        }

        ListNode* result = GetLastNode(header);
        for(int i = 1; i < lists.size();i++){
            if(lists[i] == NULL) continue;
            if(lists[i] == header) continue;
            result->next = lists[i];
            result = GetLastNode(result);            
        }
        auto vec = GetValueVector(header);
        sort(vec.begin(), vec.end());
        SetValueListNode(vec, header);

        return header;
    }
};

int main(int argc, char* argv[]){

    Solution s;

    vector<ListNode*> lists;

    lists.push_back(NULL);

    auto r11 = new ListNode(1);
    lists.push_back(r11);

    // auto r01 = new ListNode(1);
    // auto r02 = new ListNode(4);
    // auto r03 = new ListNode(5);

    // r01->next = r02;
    // r02->next = r03;

    // lists.push_back(r01);

    // auto r11 = new ListNode(1);
    // auto r12 = new ListNode(3);
    // auto r13 = new ListNode(4);

    // r11->next = r12;
    // r12->next = r13;

    // lists.push_back(r11);

    // auto r21 = new ListNode(2);
    // auto r22 = new ListNode(6);

    // r21->next = r22;

    // lists.push_back(r21);

    auto ret = s.mergeKLists(lists);

    while(true){

        if(ret == NULL)
            break;
        cout << ret->val << "-> ";

        if(ret->next == NULL)
            break;
        ret = ret->next;
    }


    // delete r01;
    // delete r02;
    // delete r03;

    // delete r11;
    // delete r12;
    // delete r13;

    // delete r21;
    // delete r22;

    return 0;
}