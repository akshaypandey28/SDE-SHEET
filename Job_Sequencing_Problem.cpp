#include<bits/stdc++.h>
using namespace std;
/* https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1 */
#define pp pair<int,int> 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
class Solution 
{
    public:
    static bool cmp(pp p1,pp p2) {
        return p1.second > p2.second;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        //i have to find the earliest ending job and any two jobs have same deadline 
        //then job with maximum profit is picked up
        
        vector<pp> v; //v.first == dead and v.second == profit
        for(int i=0; i<n; i++) v.push_back({arr[i].dead,arr[i].profit});
        sort(v.begin(),v.end(),cmp);
        
        //for(int i=0; i<n; i++) cout<<v[i].first<<" "<<v[i].second<<endl;
        vector<int> ans(2,0); //jobs and profit
        int maxi=0;
        for(int i=0; i<n; i++) maxi=max(maxi,v[i].first);
        
        vector<int> utilise(maxi+1,-1); //this is for performing the jobs at a particular unit
        
        for(int i=0; i<n; i++){ //this loop is for picking the elements from the v vector
            for(int j=v[i].first; j>0; j--){ //this loop is for checking whether a particular 
            //unit is utilise or not if not then utilise it 
                if(utilise[j]==-1){
                    utilise[j]=j;
                    ans[0]++;
                    ans[1]+=v[i].second;
                    break;
                }
            }
        }
        return ans;
    } 
};
int main(){
return 0;
}