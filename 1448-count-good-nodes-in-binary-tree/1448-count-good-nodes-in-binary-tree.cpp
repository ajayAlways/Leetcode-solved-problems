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
private:
    int res=0;
public:
    void solve(TreeNode* root,int maxVal){
        if(!root) return;
        if(root->val>=maxVal) res++;
        solve(root->left,max(root->val,maxVal));
        solve(root->right,max(root->val,maxVal));
    }
    
    int goodNodes(TreeNode* root) {
        solve(root,root->val);
        return res;
    }
};