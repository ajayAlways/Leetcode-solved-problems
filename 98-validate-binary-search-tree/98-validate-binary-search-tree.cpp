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

bool solve(TreeNode* root,TreeNode* maxNode, TreeNode* minNode){
    if(root==NULL) return true;
    if((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val)) return false;
    
    return true && solve(root->left,root,minNode) && solve(root->right,maxNode,root);
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return solve(root,NULL,NULL);
    }
};