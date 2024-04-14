#include<bits/stdc++.h>
using namespace std;
/* https://leetcode.com/problems/next-permutation/ */
void f(int n,vector<int> &v){
    int idx=-1; //actually the main approach to change it from the lsb side 
    for(int i=n-2; i>=0; i--){
        if(v[i]<v[i+1]){
            idx=i;
            break;
        }
    }
    if(idx==-1){
        return ;
    }
    for(int i=n-1; i>idx; i--){
        if(v[i]>v[idx]){
            swap(v[i],v[idx]);
            break;
        }
    }
    
    sort(v.begin()+idx+1,v.end());
    return ;

}
int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    f(n,v);
    for(int i=0; i<n; i++) cout<<v[i]<<" ";
    cout<<endl;
return 0;
}