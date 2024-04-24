#include<bits/stdc++.h>
using namespace std;
/* https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article */
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        unordered_map<int, int> mp;
        int prefixSum = 0, maxLength = 0;
        
        for (int i = 0; i < N; ++i) {
            prefixSum += A[i];
            
            if (prefixSum == K) {
                maxLength = i + 1;
            }
            
            if (mp.find(prefixSum - K) != mp.end()) {
                maxLength = max(maxLength, i - mp[prefixSum - K]);
            }
            
            if (mp.find(prefixSum) == mp.end()) {
                mp[prefixSum] = i;
            }
        }
        
        return maxLength;
    } 

};
int main(){
return 0;
}