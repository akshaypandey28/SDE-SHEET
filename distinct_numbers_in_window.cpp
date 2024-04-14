#include<bits/stdc++.h>
using namespace std;
/* https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1 */
class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        unordered_map<int,int> s;
        for(int i=0; i<k; i++) s[A[i]]++;
        vector<int> v;
        v.push_back(s.size());
        for(int i=k; i<n; i++){
            //remove the first element that is i-k
            s[A[i-k]]--;
            if(s[A[i-k]] == 0) s.erase(A[i-k]);
            //add the current element
            s[A[i]]++;
            
            v.push_back(s.size());
        }
        return v;
    }
};
int main(){
return 0;
}