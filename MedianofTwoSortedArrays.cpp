#include <iostream>   // std::cout, std::endl;
#include <algorithm>  // std::sort, std::unique
#include <vector>     // std::vector
#include <stdio.h>    // printf
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        priority_queue<int> smaller; // Max heap
        priority_queue<int, vector<int>, greater<int> > bigger; // Min heap

        if(nums1.size())
            smaller.push(nums1[0]);

        for(int i = 1; i < nums1.size(); i++){
            int number = nums1[i];
            if(number < smaller.top()){// 기준보다 작은 경우 smaller에 넣는다.
                smaller.push(number);
            }else{ // 기준보다 큰 경우 bigger에 넣는다.
                 bigger.push(number);
            }

            if(smaller.size() < bigger.size()){// smaller의 크기와 bigger의 크기가 같거나, smaller의 크기가 하나 더 크게 유지되도록 데이터를 옮긴다. 
                smaller.push(bigger.top());
                bigger.pop();
            }else if(smaller.size() > bigger.size() + 1){
                bigger.push(smaller.top());
                smaller.pop();
            }
        }

        int startNumber = 0;
        if(nums1.size() == 0){
            smaller.push(nums2[0]);
            startNumber = 1;
        }

        for(int i = startNumber; i < nums2.size(); i++){
            int number = nums2[i];
            if(number < smaller.top()){
                smaller.push(number);
            }else{
                bigger.push(number);
            }

            if(smaller.size() < bigger.size()){
                smaller.push(bigger.top());
                bigger.pop();
            }else if(smaller.size() > bigger.size() + 1){
                bigger.push(smaller.top());
                smaller.pop();
            }
        }

        
        if(smaller.size() == bigger.size()){// smaller와 bigger의 크기가 같다면 총 개수는 짝수이다.
            cout << "smaller.size() == bigger.size()" << ((double)smaller.top() + (double)bigger.top()) * 0.5f << endl;
            return ((double)smaller.top() + (double)bigger.top()) * 0.5f;
        }else{
            cout << "smaller.size() != bigger.size()" << (double)smaller.top() << endl;
            return (double)smaller.top();
        }

    }
};

int main(){

    Solution r;

    vector<int> nums1 = {};
    vector<int> nums2 = {1};
    
    cout << r.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}