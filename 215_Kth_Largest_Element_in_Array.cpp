#include<bits/stdc++.h>
using namespace std;
/* https://leetcode.com/problems/kth-largest-element-in-an-array/description/ */

//1st method
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
        }
        while(k-1>0){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};
//2nd method 
//similar to question 703
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int> ,greater<int> > pq;
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};
int main(){
return 0;
}