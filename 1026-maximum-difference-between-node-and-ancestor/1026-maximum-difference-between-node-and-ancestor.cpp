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
    void solve(TreeNode* root, int maxVal, int minVal){
        if(!root) return;
        res = max(res,max(abs(root->val - maxVal),abs(root->val - minVal)));
        maxVal = max(root->val,maxVal);
        minVal = min(root->val,minVal);
        solve(root->left,maxVal,minVal);
        solve(root->right,maxVal,minVal);
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root,root->val,root->val);
        return res;
    }
};