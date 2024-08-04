#include<bits/stdc++.h>
using namespace std;
/* https://www.geeksforgeeks.org/problems/better-string/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=better-string */
class Solution {
  public:
    int dist(string s)
    {
        unordered_map<char, int> last;
        int count = 1; //reresents empty string

        for (auto ch : s) {
            int newCount = 2 * count; // each subsequence can either include or exclude the current character

         if (last.find(ch) != last.end()) newCount -= last[ch];

            last[ch] = count; //it helps in removing the previous occurence of this character subsequences
            count = newCount;
        }
        return count;
    }

    string betterString(string s1, string s2) {
        int distSeq1 = dist(s1);
        int distSeq2 = dist(s2);

        return distSeq2 > distSeq1 ? s2 : s1;
    }
};
int main(){
return 0;
}