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
    int res=0;
public:
    
    void preOrder(TreeNode* root,string binary){
    if(root->left==NULL && root->right==NULL){
        binary+=to_string(root->val);
        res+=stoi(binary,0,2);
        return;
    }
    string cur = to_string(root->val);
    if(root->left){
        preOrder(root->left,binary+cur);
    }
    if(root->right){
        preOrder(root->right,binary+cur);
    }
    
    }
    
    int sumRootToLeaf(TreeNode* root) {
        preOrder(root,"");
        
        return res;
    }
};