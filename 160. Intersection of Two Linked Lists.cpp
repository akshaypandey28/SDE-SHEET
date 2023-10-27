#include<bits/stdc++.h>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int size1=0,size2=0;
        ListNode *a=headA,*b=headB;
        while(a!=NULL){
            size1+=1;
            a=a->next;
        }
        while(b!=NULL){
            size2+=1;
            b=b->next;
        }
        
        int size=abs(size1-size2);
        while(size--){
            if(size1>size2){
                headA=headA->next;
            }
            else if(size2>size1){
                headB=headB->next;
            }
        }
        while(headA!=NULL){
            if(headA==headB){
                return headA;
            }
            else{
                headA=headA->next;
                headB=headB->next;
            }
        }
            return headA;
    }
};
int main(){
return 0;
}