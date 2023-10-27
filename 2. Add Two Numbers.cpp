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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* ans=dummy;
        int sum=0;   int rem=0;
        while(l1!=NULL && l2!=NULL){
            sum=rem + l1->val + l2->val;
            rem=sum/10;
            l1=l1->next;
            l2=l2->next;
            if(rem==0){
                ListNode* a=new ListNode(sum);
                dummy->next=a;   }
            else{
                ListNode* a=new ListNode(sum%10);
                dummy->next=a;   }
                dummy=dummy->next;
        }
        while(l1!=NULL){
            sum=rem+l1->val;
            rem=sum/10;
            l1=l1->next;
            if(rem==0){
                ListNode* a=new ListNode(sum);
                dummy->next=a;
            }
            else{
                ListNode* a=new ListNode(sum%10);
                dummy->next=a;
            }
            dummy=dummy->next;
        }
        while(l2!=NULL){
            sum=rem+l2->val;
            rem=sum/10;
            l2=l2->next;
            if(rem==0){
                ListNode* a=new ListNode(sum);
                dummy->next=a;
            }
            else{
                ListNode* a=new ListNode(sum%10);
                dummy->next=a;
            }
            dummy=dummy->next;
        }
        if(rem>0){
            ListNode* a=new ListNode(rem);
                dummy->next=a;
        }
        return ans->next;
    }
};
int main(){
return 0;
}