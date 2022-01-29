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

void inOrder(TreeNode* root,vector<int> &v){
    if(root==NULL) return;
    inOrder(root->left,v);
    v.push_back(root->val);
    inOrder(root->right,v);
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>v;
        inOrder(root,v);
        return v[k-1];
    }
};