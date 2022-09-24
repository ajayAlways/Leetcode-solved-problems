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
    
    void solve(TreeNode* root, int tar, vector<vector<int>>&res, vector<int>&curPath){
        if(!root) return;
        if(!root->left && !root->right){
            tar-=root->val;
            curPath.push_back(root->val);
            if(tar==0){
                res.push_back(curPath);
            }
            tar+=root->val;
            curPath.pop_back();
            return;
        }
        tar-=root->val;
        curPath.push_back(root->val);
        solve(root->left,tar,res,curPath);
        solve(root->right,tar,res,curPath);
        tar+=root->val;
        curPath.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        vector<int>curPath;
        solve(root,targetSum,res,curPath);
        
        return res;
    }
};