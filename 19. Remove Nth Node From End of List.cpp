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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return head;
        }
        ListNode* curr=head;
            int size=0;
            while(curr!=NULL){
                size++;
                curr=curr->next;
            }
       
        ListNode* prev=head;
        curr=head;
        if(size==n){
            return prev->next;
        }
        int count=0;
        while(count<n){
            count++;
            curr=curr->next;
        }
        while(curr->next!=NULL){
            curr=curr->next;
            prev=prev->next;
        }
        prev->next=prev->next->next;
        return head;

    }
};
int main(){
return 0;
}