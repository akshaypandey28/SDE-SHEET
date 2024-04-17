#include<bits/stdc++.h>
using namespace std;
/* https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1 */
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=1,j=0;
    	int ans=1;
    	int count=1;
    	while(i<n and j<n){
    	    if(arr[i]<=dep[j]){ 
    	        count++;
    	        i++;
    	    }
    	    else{
    	        count--;
    	        j++;
    	    }
    	    ans=max(ans,count);
    	}
    	return ans;
    }
};
int main(){
return 0;
}