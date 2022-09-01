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
    
    int solve(TreeNode* root, int curMax){
        if(!root) return 0;
        int res = 0;
        if(root->val>=curMax) res+=1;
        curMax = max(curMax,root->val);
        res+=solve(root->left,curMax) + solve(root->right,curMax);
        
        return res;
    }
    
    int goodNodes(TreeNode* root) {
        return solve(root,INT_MIN);
    }
};