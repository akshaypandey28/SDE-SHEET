#include<bits/stdc++.h>
using namespace std;
/* https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/ */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class NodeValue {
public:
    int minNode, maxNode, maxSize, sum;
    
    NodeValue(int minNode, int maxNode, int maxSize, int sum) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
        this->sum = sum;
    }
};
class Solution {
public:
    int result=0;
    NodeValue f(TreeNode* root) {
        if (root == NULL) return NodeValue(INT_MAX, INT_MIN, 0, 0);
        
        //values of the left and right subtree of current tree
        auto left = f(root->left);
        auto right = f(root->right);
        
        //if current node is greater than max of left and smaller than min of left then 
        //it is BST
        if (root->val > left.maxNode and root->val < right.minNode) {
            //it is a BST
            int add = root->val + left.sum + right.sum;
            result=max(add,result);
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode),
            left.maxSize + right.maxSize + 1, root->val + left.sum + right.sum);
        }
        //after this line not a BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize), max(left.sum,right.sum));
    }
    int maxSumBST(TreeNode* root) {
        
        f(root);
        return result;
    }
};
int main(){
return 0;
}






/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */




/* 
MEMORY LIMIT EXCEEDED IN THIS CODE AND THIS IS WRITTEN BY MYSELF
class Solution {
public:
    int ans = 0;

    bool check(vector<int>& v) {
        if (v.size() <= 1) return true;
        for (int i = 1; i < v.size(); i++) {
            if (v[i - 1] >= v[i]) return false;
        }
        return true;
    }

    void in(TreeNode* root, vector<int>& v) {
        if (root == NULL) return;
        in(root->left, v);
        v.push_back(root->val);
        in(root->right, v);
    }

    void pre(TreeNode* root) {
        if (root == NULL) return;
        vector<int> v;
        int temp = 0;
        in(root, v);
        if (check(v)) {
            for (int i = 0; i < v.size(); i++) temp += v[i];
            ans = max(ans, temp);
        }
        pre(root->left);
        pre(root->right);
    } 

    int maxSumBST(TreeNode* root) {
        pre(root);
        return ans;
    }
};
 */