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
        int length(ListNode* head){
            ListNode* s=head;
            int size=0;
            while(s!=NULL){
            size++;
            s=s->next;
            }
            return size;
        }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* prev=NULL;
        ListNode* curr=head;
        int count=0;
        int currRecursionLength=length(head);
        if(k>currRecursionLength){
            return head;
        }
        //cout<<size<<endl;
        
        //if(size%k==0){
            while(curr!=NULL && count<k){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            count++;
            }
        //}
        if(curr!=NULL){
            ListNode* new_head= reverseKGroup(curr,k);
            head->next=new_head;
        }
        return prev;
    }
};
int main(){
return 0;
}