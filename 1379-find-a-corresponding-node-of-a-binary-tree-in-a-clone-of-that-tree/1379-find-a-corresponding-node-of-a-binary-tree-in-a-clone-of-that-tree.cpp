/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void solve(TreeNode* &original, TreeNode* &cloned, TreeNode* &target, TreeNode* &res){
    if(!original && !cloned) return;
    if(original == target){
        res = cloned;
        return;
    }
    solve(original->left,cloned->left,target,res);
    solve(original->right,cloned->right,target,res);
}

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* res=NULL;
        solve(original,cloned,target,res);
        return res;
    }
};