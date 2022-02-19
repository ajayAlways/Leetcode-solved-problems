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
    int maxLevel=1,res=0;
public:
    void dfs(TreeNode* root,int level){
        if(!root) return;
        dfs(root->left,level+1);
        if(maxLevel < level){
            res = root->val;
            maxLevel = level;
        }
        dfs(root->right,level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        res = root->val;
        dfs(root,1);
        return res;
    }
};