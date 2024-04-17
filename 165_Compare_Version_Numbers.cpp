#include<bits/stdc++.h>
using namespace std;
/* https://leetcode.com/problems/compare-version-numbers/ */
class Solution {
public:
    int compareVersion(string v1, string v2) {
        int num=0;
        vector<int> a,b;
        for(int i=0; i<v1.size(); i++){
            if(v1[i]=='.') {
                a.push_back(num);
                num=0;
                continue;
            }
            num=num*10 + (v1[i]-'0');
        }
        a.push_back(num);
        num=0;
        for(int i=0; i<v2.size(); i++){
            if(v2[i]=='.') {
                b.push_back(num);
                num=0;
                continue;
            }
            num=num*10 + (v2[i]-'0');
        }
        b.push_back(num);
        
        int i=0,j=0;
        for(int i=0; i<a.size(); i++) cout<<a[i]<<" ";
        cout<<endl;
        for(int i=0; i<b.size(); i++) cout<<b[i]<<" ";
        cout<<endl;
        while (i < a.size() || j < b.size()) {
            int num1 = (i < a.size()) ? a[i] : 0;
            int num2 = (j < b.size()) ? b[j] : 0;
            if (num1 < num2) return -1;
            else if (num1 > num2) return 1;
            i++;
            j++;
        }
        return 0;
    }
};
int main(){
return 0;
}