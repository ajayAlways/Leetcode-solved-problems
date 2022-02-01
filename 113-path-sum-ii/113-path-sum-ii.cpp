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
    vector<vector<int>>ans;
    void dfs(TreeNode* root,vector<int>&sol,int sum,int target){
        if(root->left==NULL && root->right==NULL){
            sum+=root->val;
            sol.push_back(root->val);
            if(sum==target) ans.push_back(sol);
            sum-=root->val;
            sol.pop_back();
            return;
        }
        sum+=root->val;
        sol.push_back(root->val);
        if(root->left) dfs(root->left,sol,sum,target);
        if(root->right) dfs(root->right,sol,sum,target);
        sum-=root->val;
        sol.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return {};
        vector<int>sol;
        int sum=0;
        dfs(root,sol,sum,targetSum);
        return ans;
    }
};