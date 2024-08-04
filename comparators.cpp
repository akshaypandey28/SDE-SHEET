#include<bits/stdc++.h>
using namespace std;
#define pp pair<int, string>
//1st
class cmp {
public:
    bool operator()(const pp& p1, const pp& p2) {
        // Compare based on the lexicographical order
        if (p1.first == p2.first) {
            return p1.second < p2.second;
        }
        // compare based on the integer value min heap
        return p1.first > p2.first;
    }
};


int main(){
return 0;
}