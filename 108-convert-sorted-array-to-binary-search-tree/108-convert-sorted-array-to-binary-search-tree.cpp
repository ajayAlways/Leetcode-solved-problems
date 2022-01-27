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

TreeNode* insert(vector<int>&nums,int i,int j){
    if(i>j){
        return NULL;
    }
    int mid = (j+i)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = insert(nums,i,mid-1);
    root->right = insert(nums,mid+1,j);
    return root;
}


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return insert(nums,0,nums.size()-1);

    }
};