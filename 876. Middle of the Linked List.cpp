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
    ListNode* middleNode(ListNode* head) {
        int size=0;
        ListNode* temp=head;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        if(size%2==0){
            ListNode* slow=head;
            ListNode* fast=head;
            while(fast!=NULL){
                fast=fast->next->next;
                slow=slow->next;
            }
            return slow;
        }
        else{
            ListNode* slow=head;
            ListNode* fast=head;
            while(fast->next!=NULL){
                fast=fast->next->next;
                slow=slow->next;
            }
            return slow;
        }
    }
};
int main(){
return 0;
}