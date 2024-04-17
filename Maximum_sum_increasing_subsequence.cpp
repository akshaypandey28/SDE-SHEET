#include<bits/stdc++.h>
using namespace std;
/* https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1 */

//same as leetcode 300 question
class Solution{
	public:
	vector<vector<int>> dp;
	int f(int arr[],int n,int i,int pi){
	    if(i>=n) return 0;
	    if(dp[i][pi+1]!=-1) return dp[i][pi+1];
	    int take=0;
	    int notTake=0;
	    if(arr[i]>arr[pi] || pi==-1){
	        take=arr[i]+f(arr,n,i+1,i);
	    }
	    notTake=f(arr,n,i+1,pi);
	    return dp[i][pi+1]=max(take,notTake);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    dp.clear();
	    dp.resize(n+1,vector<int>(n+1,-1));
	    return f(arr,n,0,-1);
	}  
};
int main(){
return 0;
}