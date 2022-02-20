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
    void dfs(TreeNode* root,int l,vector<int> &level){
        if(!root) return;
        if(level.size() < l) level.push_back(root->val);
        level[l-1] = max(level[l-1],root->val);
        dfs(root->left,l+1,level);        
        dfs(root->right,l+1,level);
    }
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int>res;
        // queue<TreeNode*>q;
        // vector<int>res;
        // q.push(root);
        // while(!q.empty()){
        //     int size = q.size(),maxVal=INT_MIN;
        //     while(size--){
        //         TreeNode* node = q.front();
        //         q.pop();
        //         maxVal = max(maxVal, node->val);
        //         if(node->left) q.push(node->left);
        //         if(node->right) q.push(node->right);
        //     }
        //     res.push_back(maxVal);
        // }
        dfs(root,1,res);
        return res;
    }
};