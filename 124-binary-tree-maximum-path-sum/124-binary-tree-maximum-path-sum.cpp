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
    int solve(TreeNode* root,int &res){
        if(!root) return 0;
        int left = solve(root->left,res);
        int right = solve(root->right,res);
        int single_ans = max(max(left,right)+root->val,root->val);
        int temp_ans = max(single_ans,left+right+root->val);
        res = max(res,temp_ans);
        return single_ans;
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        int temp = solve(root,res);
        return res;
    }
};