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
    int sumLeft=0,totalSum;
public:
    int sum(TreeNode* root){
        if(!root) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
    void inOrder(TreeNode* root){
        if(!root) return;
        inOrder(root->left);
        int val = root->val;
        root->val = totalSum - sumLeft;
        sumLeft+=val;
        inOrder(root->right);
        
    }
    TreeNode* bstToGst(TreeNode* root) {
        totalSum = sum(root);
        inOrder(root);
        return root;
    }
};