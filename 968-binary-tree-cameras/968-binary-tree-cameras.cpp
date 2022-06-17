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
    unordered_set<TreeNode*>s;
    int ans;
public:
    void dfs(TreeNode* root, TreeNode* par){
        if(root==NULL) return;
        dfs(root->left,root);
        dfs(root->right,root);
        if((par==NULL && !s.count(root)) || !s.count(root->left) || !s.count(root->right)){
            ans++;
            s.insert(root);
            s.insert(par);
            s.insert(root->left);
            s.insert(root->left);
        }
    }
    int minCameraCover(TreeNode* root) {
        ans = 0;
        s.insert(NULL);
        dfs(root,NULL);
        return ans;
    }
};