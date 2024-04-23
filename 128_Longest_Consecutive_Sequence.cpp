#include<bits/stdc++.h>
using namespace std;
/* https://leetcode.com/problems/longest-consecutive-sequence/description/ */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int result=1;
        unordered_set<int> s;
        for (int i = 0; i < n; i++) s.insert(nums[i]);
        //what i have to do in this question 
        //i have to just find the starting number , if any starting number is found then i have to check 
        //whether a consecutive sequence present or not from that number
        //example if [100,4,200,1,3,2]
        //here 100 ,200, 1 is a starting number 
        //how can i find the starting number => if a number is starting number then its previous must not be 
        //present in the set
        for(auto it:s){
            //if 'it' is a starting number:
            if(s.find(it-1)==s.end()){
                int count=1; //for the current element
                int x=it;
                while(s.find(x+1)!=s.end()){
                    x++;
                    count++;
                }
                result=max(result,count);
            }
        }
        return result;
    }
};
int main(){
return 0;
}