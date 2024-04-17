#include<bits/stdc++.h>
using namespace std;
/* https://leetcode.com/problems/count-and-say/ */
class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        for(int i=2; i<=n; i++){
            string temp="";
            int j=0;
            while(j<ans.size()){
                int count=0;
                char ch=ans[j];
                while(j<ans.size() and ans[j]==ch){
                    count++;
                    j++;
                }
                temp+=to_string(count)+ch;
            }
            ans=temp;
        }
        return ans; 
    }
};
int main(){
return 0;
}