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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1=list1;
        ListNode* head2=list2;
        ListNode* dummy=new ListNode(-1);
        ListNode* new_head=dummy;
        while(head1!=NULL && head2!=NULL){
            if(head1->val < head2->val){
                dummy->next=head1;
                head1=head1->next;
                //head2=dummy;
            }
            else{
                dummy->next=head2;
                head2=head2->next;
            }
            dummy=dummy->next;
        }
        if(head1!=NULL){
            dummy->next=head1;
        }
        else{
            dummy->next=head2;
        }
        return new_head->next;
    }
};
int main(){
return 0;
}