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
    void inOrder(TreeNode* root, vector<int> &res){
        if(!root) return;
        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }
    TreeNode* makeBST(TreeNode* root,int start, int end, vector<int>res){
        if(start>end) return NULL;
        int mid = (start + end)/2;
        root = new TreeNode(res[mid]);
        root->left = makeBST(root->left,start,mid-1,res);
        root->right = makeBST(root->right,mid+1,end,res);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>res;
        inOrder(root,res);
        root = makeBST(NULL,0,res.size()-1, res);
        return root;
    }
};