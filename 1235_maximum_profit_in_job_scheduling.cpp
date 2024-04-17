#include<bits/stdc++.h>
using namespace std;
/* https://leetcode.com/problems/maximum-profit-in-job-scheduling/ */
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        vector<vector<int>> jobs;
        for(int i=0; i<startTime.size(); i++){
            jobs.push_back( { startTime[i],endTime[i], profit[i] } );
        }
        sort( jobs.begin(), jobs.end() );
        priority_queue< vector<int> ,vector<vector<int>> ,greater<vector<int>> > pq;
        //earliest ending job that is pq
        int mp=0; // this is maxprofit
        for(int i=0; i<jobs.size(); i++){
            int start=jobs[i][0];
            int end=jobs[i][1];
            int profit=jobs[i][2];
            while( !pq.empty() && start >= pq.top()[0] ){
                mp=max(mp,pq.top()[1] );
                pq.pop();
            }
            pq.push( {end, profit+mp } );
        }
        while(!pq.empty()){
            mp=max(mp,pq.top()[1] );
            pq.pop();
        }
        return mp;
    }
};
int main(){
return 0;
}