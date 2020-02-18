#include <algorithm>  // std::sort, std::unique
#include <vector>     // std::vector
#include <stdio.h>    // printf
#include <iostream>
#include <string>     // std::string
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void func_save_vec(ListNode *l, vector<int> &note){
    note.push_back(l->val);
    if(l->next != NULL){
       return func_save_vec(l->next, note);
    }else{
       return;
    }
}

void func_make_pointer(ListNode *l, vector<int> &note, int pos){
    if(pos + 1 < note.size()){
        auto ret = new ListNode(note.at(pos+1));
        l->next = ret;
        return func_make_pointer(ret, note, pos+1);
    }else{
        return;
    } 
}

vector<int> func(vector<int> &s1, vector<int> &s2){

    int index = max(s1.size(), s2.size());
    auto c = vector<int>();
    bool isOver10 = false;
    for(int i = 0; i < index; i++){        
        int a = (i < s1.size()) ? s1.at(i) : 0;
        int b = (i < s2.size()) ? s2.at(i) : 0;   
        int calc = isOver10 ? (a + b + 1) : (a + b);

        if (calc >= 10){
            calc -= 10;
            isOver10 = true;
        }else{
            isOver10 = false;
        }
        c.push_back(calc);
        if(i == index - 1 && isOver10){
            c.push_back(1);
        }
    }

    return c;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> s1;
        func_save_vec(l1, s1);

        vector<int> s2;
        func_save_vec(l2, s2);

        auto r = func(s1, s2);

        auto p = new ListNode((int)r.at(0));
        func_make_pointer(p, r, 0);

        return p;
    }
};

int main(){
    // auto l11 = new ListNode(2);
    // auto l12 = new ListNode(4);
    // auto l13 = new ListNode(3);
    
    // l11->next = l12;
    // l12->next = l13;

    auto l11 = new ListNode(9);

    // auto l21 = new ListNode(5);
    // auto l22 = new ListNode(6);
    // auto l23 = new ListNode(4);

    // l21->next = l22;
    // l22->next = l23;

    auto l20 = new ListNode(1);

    auto l21 = new ListNode(9);
    auto l22 = new ListNode(9);
    auto l23 = new ListNode(9);
    auto l24 = new ListNode(9);
    auto l25 = new ListNode(9);
    auto l26 = new ListNode(9);
    auto l27 = new ListNode(9);
    auto l28 = new ListNode(9);
    auto l29 = new ListNode(9);

    l20->next = l21;
    l21->next = l22;
    l22->next = l23;
    l23->next = l24;
    l24->next = l25;
    l25->next = l26;
    l26->next = l27;
    l27->next = l28;
    l28->next = l29;
    
    auto s = new Solution();
    auto ret = s->addTwoNumbers(l11, l20);
    
    cout << ret->val << endl;

    delete ret;
    delete s;


    // delete l11;
    // delete l12;
    // delete l13;
    // delete l21;
    // delete l22;
    // delete l23;


    delete l11;
    delete l20;
    delete l21;
    delete l22;
    delete l23;
    delete l24;
    delete l25;
    delete l26;
    delete l27;
    delete l28;
    delete l29;

    return 0;
}