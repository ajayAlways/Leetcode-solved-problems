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
    int solve(TreeNode* root, int p, int gp){
        if(root==NULL) return 0;
        
        return solve(root->left,root->val,p) + solve(root->right,root->val,p) + (gp%2 ? 0:root->val);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        // queue<TreeNode*>q;
        // q.push(root);
        // int res=0;
        // while(!q.empty()){
        //     TreeNode* node = q.front();
        //     q.pop();
        //     if(node->val % 2==0){
        //         if(node->left && node->left->left) res+=node->left->left->val;
        //         if(node->left && node->left->right) res+=node->left->right->val;
        //         if(node->right && node->right->left) res+=node->right->left->val;
        //         if(node->right && node->right->right) res+=node->right->right->val;
        //     }
        //     if(node->left) q.push(node->left);
        //     if(node->right) q.push(node->right);
        // }
        int res = solve(root,1,1);
        return res;
    }
};