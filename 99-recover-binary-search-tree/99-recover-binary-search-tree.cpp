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
class Solution {
public:
    void inOrder(TreeNode* root, vector<int> &arr){
        if(!root) return;
        inOrder(root->left, arr);
        arr.push_back(root->val);
        inOrder(root->right, arr);
    }
    void change(TreeNode* root,vector<int>arr, int &i){
        if(!root) return;
        change(root->left,arr,i);
        root->val = arr[i++];
        change(root->right,arr,i);
    }
    void recoverTree(TreeNode* root) {
        int i=0;
        vector<int>arr;
        inOrder(root,arr);
        sort(arr.begin(),arr.end());
        change(root, arr,i);
    }
};