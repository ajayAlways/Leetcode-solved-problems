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
    
    int solve(TreeNode* root, vector<int>&freq){
        if(root==NULL) return 0;
        if(!root->left && !root->right){
            freq[root->val]++;
            int odds = 0;
            for(auto& i:freq) odds+=i%2;
            freq[root->val]--;
            if(odds<=1) return 1;
            return 0;
        }
        freq[root->val]++;
        int res = solve(root->left,freq) + solve(root->right,freq);
        freq[root->val]--;
        return res;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>freq(10,0);
        return solve(root,freq);
    }
};