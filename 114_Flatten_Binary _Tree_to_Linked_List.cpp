#include<bits/stdc++.h>
using namespace std;
/* https://leetcode.com/problems/flatten-binary-tree-to-linked-list/ */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* temp=NULL;

    /* 
    T.C and S.C => O(N)
     */
    void flatten(TreeNode* root) {
        if(root==NULL) return ;
        //reverse preorder traversal
        flatten(root->right);
        flatten(root->left);

        root->right=temp;
        root->left=NULL;

        temp=root;
        return ;
    }
};
int main(){
return 0;
}