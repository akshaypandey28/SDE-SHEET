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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL &&  fast->next!=NULL){
                fast=fast->next->next;
                slow=slow->next;
            }
        ListNode* prev=NULL;
        ListNode* curr=slow;
        while(curr!=NULL){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        
        //now prev is pointing to last node of ll
        ListNode* head1=head;
        while(prev!=NULL){
            if(prev->val!=head1->val){
                return false;
            }
            prev=prev->next;
            head1=head1->next;
        }
        return true;
    }
};
int main(){
return 0;
}