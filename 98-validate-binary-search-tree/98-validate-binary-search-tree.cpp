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
    bool isValidBST(TreeNode* root,long maxi, long mini){
        if(!root) return true;
        return root->val > mini && root->val < maxi && isValidBST(root->left, root->val, mini) && isValidBST(root->right, maxi, root->val);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,LONG_MAX, LONG_MIN);
    }
};