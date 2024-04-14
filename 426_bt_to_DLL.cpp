#include<bits/stdc++.h>
using namespace std;
/* https://www.geeksforgeeks.org/problems/binary-tree-to-dll/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
// This function should return head to the DLL
class Solution
{
    public: 
    //2nd method
    vector<int> v;
    void in(Node* root){
        if(root==NULL) return ;
        in(root->left);
        v.push_back(root->data);
        in(root->right);
    }
    
    //1st method 
    Node* temp=NULL;
    Node* head=temp;
    void f(Node* root){
        if(root==NULL) return ;
        f(root->left);
        Node* currNode=new Node(root->data);
        if(temp==NULL){
            temp=currNode;
            head=temp;
        }
        else{
            temp->right=currNode;
            currNode->left=temp;
            temp=currNode;
        }
        f(root->right);
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here
        //1st method 
        f(root);
        return head;
        
        //2nd method
        in(root);
        if(v.size()==0) return NULL;
        Node* temp=new Node(v[0]);
        Node* head=temp;
        for(int i=1; i<v.size(); i++){
            Node* curr=new Node(v[i]);
            temp->right=curr;
            curr->left=temp;
            temp=temp->right;
        }
        return head;
    }
};
int main(){
return 0;
}